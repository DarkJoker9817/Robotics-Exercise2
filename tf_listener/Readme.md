# TF Listener

The `TF Listener` package contains code for a ROS node ([listener.cpp](./src/listener.cpp)) that implements a listener that heards messages from ```/tf``` topic to retrieve informations about transformations and uses them to compute and visualize to stdout other representations (Quaternion, Axis-Angle, Rotation-Matrix, Euler Angles).

In [script](./script/) folder there is a MATLAB file you can use to verify computations.
