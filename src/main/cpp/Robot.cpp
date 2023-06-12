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
  double multiply = (Driver.GetLeftX() % 2 == 0) ? 1 : -1;
  double aPressed = (Driver.GetAButtonPressed() == true) ? -0.95 : -0.15;
  double bPressed = (Driver.GetBButtonPressed() == true) ? -0.975 : 0;
  Right1.Set(ControlMode::PercentOutput, forwardSpeed * multiply);
  Right2.Set(ControlMode::PercentOutput, forwardSpeed * multiply);
  Right3.Set(ControlMode::PercentOutput, forwardSpeed * multiply);
  Left1.Set(ControlMode::PercentOutput,  forwardSpeed * -multiply);
  Left2.Set(ControlMode::PercentOutput,  forwardSpeed * -multiply);
  Left3.Set(ControlMode::PercentOutput,  forwardSpeed * -multiply);
  Intake.Set(ControlMode::PercentOutpt, aPressed)   ShooterLeft.Set(ControlMode::PercentOutput, bPressed);
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