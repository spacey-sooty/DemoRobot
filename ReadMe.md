# DemoBot

This is the code for CurtinFRC's DemoBot for outreach usage. It is designed to be simple and also work.

## Systems

This DemoBot consists of 2 key systems, the drivebase which is a 6 cim tread and the intake/shooter.

### Drivebase

The drivebase is controlled using the TalonSRX Motor Controller from the ctre. When being referred to in code db is drivebase. It is coded using the pheonix library. The controls operate very simply, forward or backwards on the left joystick for forwards and backwards motion. To turn left and right on the right joystick can be used to spin the robot in those directions.

### Intake/Shooter