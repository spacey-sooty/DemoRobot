# DemoBot

This is the code for CurtinFRC's DemoBot for outreach usage. It is designed to be simple and also work.

## Systems

This DemoBot consists of 2 key systems, the drivebase which is a 6 cim tread and the intake/shooter.

### Drivebase

The drivebase is controlled using the TalonSRX Motor Controller from the ctre. It is coded using the pheonix library. The controls operate very simply, forward or backwards on the left joystick for forwards and backwards motion. To turn left and right on the left joystick can be used to spin the robot in those directions.

### Intake/Shooter

For the Shooter you can control it using the Xbox Controllers B button. When you press it it will shoot. Before you shoot you will need to intake a ball. This can be done by pressing the A button.