# Ex2 Tranforms

## The task

* Derive DH parameters for the Fanuc robot.
* Translate DH parameters to URDF and visualize the Fanuc robot in RViz with urdf_tutorial display.launch.
* Create a fanuc_moveit_config package and visualize the robot in RViz.
* Visualize TFs in RViz and write one or more ROS nodes to compute and print the TF of the end-effector in all the reference frames of all joints. From the TF, compute the translational vector, the rotation matrix, the Euler angles and the axis-angle representation.
* Verify the results by comparing with manual/MATLAB calculations.

---

## Repository content

This repository is composed by three ROS packages:

* `fanuc_description` package that contains the URDF the description for the M-20iA robot according to the [datasheet](https://www.fanuc.com/fvl/vn/product/catalog/RM-10iA(E)-07.pdf)
* `m-20ia_moveit_config` package that contains all the config and launch file for the robot generated with MoveIt! tool
* `tf_listener` package that contains a node that compute the TF in addition to MATLAB script to verify computations
