# Robotica-Exercise2
1. Derive DH parameters for the Fanuc robot.
2. Translate DH parameters to URDF and visualize the Fanuc robot in RViz with urdf_tutorial display.launch.
3. Create a fanuc_moveit_config package and visualize the robot in RViz.
4. Visualize TFs in RViz and write one or more ROS nodes to compute and print the TF of the end-effector in all the reference frames of all joints. From the TF, compute the translational vector, the rotation matrix, the Euler angles and the axis-angle representation.
5. Verify the results by comparing with manual/MATLAB calculations.

## How to run
1. Copy packages to your workspace then build them:
```bash
catkin build
```
2. Source your workspace:
```bash
source devel/setup.bash
```
4. Launch following command to start visualizing and publishing TF on /tf topic
```bash
roslaunch m20iA_moveit_config demo.launch use_gui:=true
```
5. Open a new shell window and source:
```bash
source devel/setup.bash
```
6. Launch following command to start the TFListener node
```bash
rosrun fanuc_TFListener tf_listener
```
7. Launch fanuc_TFListener/script/Fanuc_m20iA_FK.m in Matlab to compare the results
