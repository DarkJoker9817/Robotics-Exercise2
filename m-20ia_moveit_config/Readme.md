# M-20iA MoveIt Config

The `m-20ia_moveit_config` package was generated using the [MoveIt Setup Assistant](http://docs.ros.org/en/kinetic/api/moveit_tutorials/html/doc/setup_assistant/setup_assistant_tutorial.html) and the URDF configuration file for the Fanuc M-20iA robot created in [fanuc_description package](../fanuc_description/)

To run this assistant execute the command:

``` bash
roslaunch moveit_setup_assistant setup_assistant.launch
```

---

After building the generated package you can run a visualization of the robot in rviz by executing the command below:

```bash
roslaunch m-20ia_moveit_config demo.launch
```

To be able to move robot joints make sure to set the ```use_gui``` argument to ```true``` in ```demo.launch``` file:

```xml
<arg name="use_gui" default="true"/>
```
