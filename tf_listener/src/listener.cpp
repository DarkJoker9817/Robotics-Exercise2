/* 
 * -------------------------------------------------------------------
 * This module has been developed as an exercise for Robotics course 
 * @ UniSa.
 *
 * Title:   listener.cpp
 * Author:  Ugo Barbato
 * Date:    Oct 20, 2022
 *
 * This module implements a listener that heards messages from the topic 
 * "/tf" in order to parse and show them to stdout.
 *
 * -------------------------------------------------------------------
 */

#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

int main(int argc, char** argv) {

    ros::init(argc, argv, "tf_listener");
    ros::NodeHandle nh;

    /*
    * Declare a TransformListener wrapper with the relative buffer to store
    * information in.
    */
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Rate rate(1); // ten times in a second

    while(ros::ok()) {
        /*
        * Declare a std::vector of TransformStamped to store transforms from
        * from each link to the flange.
        */
        std::vector<geometry_msgs::TransformStamped> transforms(7);
        try {
            transforms[0] = tfBuffer.lookupTransform("base_link", "flange", ros::Time(0));
            transforms[1] = tfBuffer.lookupTransform("link_1", "flange", ros::Time(0));
            transforms[2] = tfBuffer.lookupTransform("link_2", "flange", ros::Time(0));
            transforms[3] = tfBuffer.lookupTransform("link_3", "flange", ros::Time(0));
            transforms[4] = tfBuffer.lookupTransform("link_4", "flange", ros::Time(0));
            transforms[5] = tfBuffer.lookupTransform("link_5", "flange", ros::Time(0));
            transforms[6] = tfBuffer.lookupTransform("link_6", "flange", ros::Time(0));
        } catch(tf2::TransformException exception) {
            ROS_WARN("%s", exception.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        /*
        * Construct the message to be shown
        */
        for(int i=0; i<transforms.size(); i++) {
            std::ostringstream str;

            str << std::endl << std::endl << "******** Transformation from " <<
            transforms[i].header.frame_id << " to " << transforms[i].child_frame_id <<
            " ********" << std::endl;
            str << "------- Translation -------" << std::endl;
            str << transforms[i].transform.translation << std::endl;
            str << "--------- Rotation --------" << std::endl;
            str << transforms[i].transform.rotation << std::endl;

            /*
            * From the transform it is possible to save the quaternion and 
            * retrieve the rotation axis, the angle and rotation matrix
            */
            tf2::Quaternion quaternion;
            tf2::fromMsg(transforms[i].transform.rotation, quaternion);
            tf2::Vector3 rotation_axis = quaternion.getAxis();

            str << "------- Axis-Angle -------" << std::endl;
            str << "Axis = [" << rotation_axis.getX() << " " << rotation_axis.getY() << " " << rotation_axis.getZ() << "]" << std::endl;
            str << "Angle = [" << quaternion.getAngle() << "]" << std::endl;

            tf2::Matrix3x3 matrix(quaternion);
            str << "------- Rotation Matrix -------" << std::endl;
            str << "[" << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << "]" << std::endl;
            str << "[" << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << "]" << std::endl;
            str << "[" << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << "]" << std::endl;

            tf2Scalar roll, pitch, yaw;
            matrix.getRPY(roll, pitch, yaw);
            str << "------- Euler Angles -------" << std::endl;
            str << "RPY = [" << roll << " " << pitch << " " << yaw <<"]" << std::endl;

            ROS_INFO_STREAM(str.str());
        }

        rate.sleep();
    }

    ros::shutdown();
    return 0;
}

