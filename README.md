# Giant Propeller

Soliwords part files, Eagle files, and Arduino files

The goal of this project was
to replace the Giant
Propeller controls with a
newer and more robust
version. The old system
used a potentiometer to
control an industrial motor
controller. The problem
with the original system is
that the potentiometer was
susceptible to being over
turned and breaking. To
remedy this, an optical split
sensor is used to measure
the speed of the hand
crank. After the speed of
the crank is read, the
onboard Teensy outputs an
analog signal to an op-amp.
That op-amp signal then
controls 0-10v to adjust the
speed of the motor
controller. All this is
assembled on a custom
circuit board. This new set
up has no physical end
points which holds up
better to children. Since
install, we have calibrated
the sensitivity, but no
repairs for everyday use.
