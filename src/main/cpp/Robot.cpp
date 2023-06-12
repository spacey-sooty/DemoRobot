#include "Robot.h"

frc::XboxController Driver{0};
TalonSRX Intake{999};
TalonSRX ShooterLeft{999};
TalonSRX ShooterRight{999};
TalonSRX Left1{999};
TalonSRX Left2{999};
TalonSRX Left3{999};
TalonSRX Right1{999};
TalonSRX Right2{999};
TalonSRX Right3{999};

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  double forwardSpeed = (Driver.GetLeftY() > 0.15 or Driver.GetLeftY() < -0.15) ? Driver.GetLeftY() : 0;
  double turn = (Driver.GetLeftX() > 0.15 or Driver.GetLeftY() < -0.15) ? Driver.GetLeftX() : 0;
  double aPressed = (Driver.GetAButtonPressed() == true) ? -0.95 : -0.15;
  double bPressed = (Driver.GetBButtonPressed() == true) ? -0.975 : 0;
  Right1.Set(ControlMode::PercentOutput, forwardSpeed + turn);
  Right2.Set(ControlMode::PercentOutput, forwardSpeed + turn);
  Right3.Set(ControlMode::PercentOutput, forwardSpeed + turn);
  Left1.Set(ControlMode::PercentOutput,  forwardSpeed + turn);
  Left2.Set(ControlMode::PercentOutput,  forwardSpeed + turn);
  Left3.Set(ControlMode::PercentOutput,  forwardSpeed + turn);
  Intake.Set(ControlMode::PercentOutput, aPressed);
  ShooterLeft.Set(ControlMode::PercentOutput, bPressed);
  ShooterRight.Set(ControlMode::PercentOutput, bPressed);
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif