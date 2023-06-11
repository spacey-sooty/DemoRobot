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
  if (Driver.GetLeftY() > 0.15) {
    Right1.Set(ControlMode::PercentOutput, Driver.GetLeftY());
    Right2.Set(ControlMode::PercentOutput, Driver.GetLeftY());
    Right3.Set(ControlMode::PercentOutput, Driver.GetLeftY());
    Left1.Set(ControlMode::PercentOutput, Driver.GetLeftY());
    Left2.Set(ControlMode::PercentOutput, Driver.GetLeftY());
    Left3.Set(ControlMode::PercentOutput, Driver.GetLeftY());
  }

  else if (Driver.GetLeftX() > 0.15) {
    Right1.Set(ControlMode::PercentOutput, Driver.GetLeftX());
    Right2.Set(ControlMode::PercentOutput, Driver.GetLeftX());
    Right3.Set(ControlMode::PercentOutput, Driver.GetLeftX());
    Left1.Set(ControlMode::PercentOutput, -Driver.GetLeftX());
    Left2.Set(ControlMode::PercentOutput, -Driver.GetLeftX());
    Left3.Set(ControlMode::PercentOutput, -Driver.GetLeftX());
  }

  else if (Driver.GetAButtonPressed() == true) {
    Intake.Set(ControlMode::PercentOutput, -0.85);
  }
  else if (Driver.GetBButtonPressed() == true) {
    ShooterLeft.Set(ControlMode::PercentOutput, -0.95);
    ShooterRight.Set(ControlMode::PercentOutput, -0.95);
  }
  else  {
    Intake.Set(ControlMode::PercentOutput, -.075);
  }
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