# Fanuc Description

This package contains everything you need to define and visualize the M-20iA robot.

* `robot` directory contains `M-20iA.urdf` file containing the description of Fanuc M-20iA robot. This URDF uses the Denavit-Hartengberg (DH) conventions to place the reference frames of the joints.
* `mehes` directory contains the visual and collision meshes used in URDF description file.
* `doc` directory contains DH conventions used in URDF description file.

---

Preview of the robot using RViz
With rviz software we can visualize the robot structure defined in `robot/M-20iA.urdf` file descriptor. The command is:

```bash
cd fanuc_description/robot/
roslaunch urdf_tutorial display.launch model:=M-20iA.urdf
```
