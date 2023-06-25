#include "Robot.h"

frc::XboxController Driver{0};
TalonSRX Intake{12};
TalonSRX ShooterLeft{4};
VictorSPX ShooterRight{11};
TalonSRX Left1{7};
TalonSRX Left2{3};
TalonSRX Left3{16};
TalonSRX Right1{5};
TalonSRX Right2{6};
TalonSRX Right3{1};

frc::DoubleSolenoid Solenoid{1, frc::PneumaticsModuleType::CTREPCM, 0, 1};
frc::Compressor compressor{1, frc::PneumaticsModuleType::CTREPCM};

void Robot::RobotInit() {
  compressor.Enabled();
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  double right = (fabs(Driver.GetLeftY()) > 0.15) ? Driver.GetLeftY() : 0;
  double left = (fabs(Driver.GetRightY()) > 0.15) ? Driver.GetRightY() : 0;
  double aPressed = (Driver.GetAButtonPressed() == true) ? -0.3 : -0;
  double trigger = (fabs(Driver.GetRightTriggerAxis()) > 0.15) ? Driver.GetRightTriggerAxis() : 0;
  // Right1.Set(ControlMode::PercentOutput, -right);
  // Right2.Set(ControlMode::PercentOutput, -right);
  // stopping and starting
  Right3.Set(ControlMode::PercentOutput, right);
  Left1.Set(ControlMode::PercentOutput, -left);
  // Left2.Set(ControlMode::PercentOutput, left);
  // Left3.Set(ControlMode::PercentOutput, -left);
  // Intake.Set(ControlMode::PercentOutput, aPressed);
  // ShooterLeft.Set(ControlMode::PercentOutput, trigger);
  // ShooterRight.Set(ControlMode::PercentOutput, trigger);
  if (Driver.GetXButtonPressed()) { Solenoid.Toggle(); }
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