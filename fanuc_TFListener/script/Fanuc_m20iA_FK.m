% Fanuc m-20iA verify calculations
q = zeros(6,1)

dh_params = [   0.525,   q(1),      0.15,   pi/2;
                0,       q(2)+pi/2, 0.79,   0;
                0,       q(3),      0.15,   pi/2;
                0.860    q(4),      0,      -pi/2;
                0,       q(5),      0       pi/2;
                0.1,     q(6),      0,      0       ]

% tz*Rz*tx*Rx
T01 = trvec2tform([0,0,dh_params(1,1)]) * rotm2tform(rotz(rad2deg(dh_params(1,2)))) * trvec2tform([dh_params(1,3),0,0]) * rotm2tform(rotx(rad2deg(dh_params(1,4))))
T12 = trvec2tform([0,0,dh_params(2,1)]) * rotm2tform(rotz(rad2deg(dh_params(2,2)))) * trvec2tform([dh_params(2,3),0,0]) * rotm2tform(rotx(rad2deg(dh_params(2,4))))
T23 = trvec2tform([0,0,dh_params(3,1)]) * rotm2tform(rotz(rad2deg(dh_params(3,2)))) * trvec2tform([dh_params(3,3),0,0]) * rotm2tform(rotx(rad2deg(dh_params(3,4))))
T34 = trvec2tform([0,0,dh_params(4,1)]) * rotm2tform(rotz(rad2deg(dh_params(4,2)))) * trvec2tform([dh_params(4,3),0,0]) * rotm2tform(rotx(rad2deg(dh_params(4,4))))
T45 = trvec2tform([0,0,dh_params(5,1)]) * rotm2tform(rotz(rad2deg(dh_params(5,2)))) * trvec2tform([dh_params(5,3),0,0]) * rotm2tform(rotx(rad2deg(dh_params(5,4))))
T56 = trvec2tform([0,0,dh_params(6,1)]) * rotm2tform(rotz(rad2deg(dh_params(6,2)))) * trvec2tform([dh_params(6,3),0,0]) * rotm2tform(rotx(rad2deg(dh_params(6,4))))

T46 = T45*T56
T36 = T34*T46
T26 = T23*T36
T16 = T12*T26
T06 = T01*T16

% From frame5 to frame6
t56 = tform2trvec(T56) % transformation vector
R56 = tform2rotm(T56) % rotation matrix
a_a56 = tform2axang(T56) % axis-angle
rpy56 = tform2eul(T56,"ZYX") % roll-pitch-yaw

% From frame4 to frame6
t46 = tform2trvec(T46) % transformation vector
R46 = tform2rotm(T46) % rotation matrix
a_a46 = tform2axang(T46) % axis-angle
rpy46 = tform2eul(T46,"ZYX") % roll-pitch-yaw

% From frame3 to frame6
t36 = tform2trvec(T36) % transformation vector
R36 = tform2rotm(T36) % rotation matrix
a_a36 = tform2axang(T36) % axis-angle
rpy36 = tform2eul(T36,"ZYX") % roll-pitch-yaw

% From frame4 to frame6
t26 = tform2trvec(T26) % transformation vector
R26 = tform2rotm(T26) % rotation matrix
a_a26 = tform2axang(T26) % axis-angle
rpy26 = tform2eul(T26,"ZYX") % roll-pitch-yaw

% From frame1 to frame6
t16 = tform2trvec(T16) % transformation vector
R16 = tform2rotm(T16) % rotation matrix
a_a16 = tform2axang(T16) % axis-angle
rpy16 = tform2eul(T16,"ZYX") % roll-pitch-yaw

% From base_frame to frame6
t06 = tform2trvec(T06) % transformation vector
R06 = tform2rotm(T06) % rotation matrix
a_a06 = tform2axang(T06) % axis-angle
rpy06 = tform2eul(T06,"ZYX") % roll-pitch-yaw

