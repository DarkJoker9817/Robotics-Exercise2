#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

int main(int argc, char **argv)
{

	ros::init(argc, argv, "tf_listener");
	ros::NodeHandle node;

	tf2_ros::Buffer tfBuffer;
	tf2_ros::TransformListener tfListener(tfBuffer);
	ros::Rate rate(1.0);

	ros::Duration(1.0).sleep();


	while (ros::ok())
	{
		std::vector<geometry_msgs::TransformStamped> transforms(7);

		try
		{
			transforms[0] = tfBuffer.lookupTransform("base_link", "flange", ros::Time(0));
			transforms[1] = tfBuffer.lookupTransform("link1", "flange", ros::Time(0));
			transforms[2] = tfBuffer.lookupTransform("link2", "flange", ros::Time(0));
			transforms[3] = tfBuffer.lookupTransform("link3", "flange", ros::Time(0));
			transforms[4] = tfBuffer.lookupTransform("link4", "flange", ros::Time(0));
			transforms[5] = tfBuffer.lookupTransform("link5", "flange", ros::Time(0));
			transforms[6] = tfBuffer.lookupTransform("link6", "flange", ros::Time(0));
		}
		catch (tf2::TransformException exception)
		{
			ROS_WARN("%s", exception.what());
			ros::Duration(1.0).sleep();
		}

		for(int i=0; i<transforms.size(); i++)
		{
			std::ostringstream ss;

			ss << std::endl << "From " << transforms[i].header.frame_id << " to " << transforms[i].child_frame_id << std::endl;

			// Translation Vector
			ss << std::endl << "Translation" << std::endl;
			ss << transforms[i].transform.translation <<std::endl;

			tf2::Quaternion quaternion;
			quaternion.setX(transforms[i].transform.rotation.x);
			quaternion.setY(transforms[i].transform.rotation.y);
			quaternion.setZ(transforms[i].transform.rotation.z);
			quaternion.setW(transforms[i].transform.rotation.w);

			// Rotation Matrix notation
			tf2::Matrix3x3 matrix(quaternion);
			ss << std::endl << "Rotation Matrix" << std::endl;
			ss << "[ " << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << " ]" << std::endl;
			ss << "[ " << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << " ]" << std::endl;
			ss << "[ " << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << " ]" << std::endl;
			
			// Axis/Angle notation
			tf2::Vector3 rotation_axis = quaternion.getAxis();
			tf2Scalar rotation_angle = quaternion.getAngle();
			ss << std::endl << "Axis/Angle" << std::endl;
			ss << "Axis = [" << rotation_axis.getX() << " " << rotation_axis.getY() << " " << rotation_axis.getZ() << "]" << std::endl;
			ss << "Angle = " << rotation_angle << std::endl;
			
			// Roll-Pitch-Yaw Notation
			tf2Scalar roll, pitch, yaw;
			matrix.getRPY(roll, pitch, yaw);
			ss << std::endl << "Roll - Pitch - Yaw" << std::endl;
			ss << roll << " - " << pitch << " - " << yaw << std::endl;


			ROS_INFO_STREAM(ss.str());
		}

		rate.sleep();
	}

	ros::shutdown();
	return 0;
}