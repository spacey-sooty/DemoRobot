#include "shooter.h"

shooter::shooter(shooterConfig config, frc::XboxController &_driver) : _config(config), _driver(_driver) {}

void shooter::OnStart() {
  std::cout << "Starting" << std::endl;
}

void shooter::OnUpdate(units::second_t dt) {
  switch(_state) {
    case shooterState::kIdle :
      break;
    
    case shooterState::kShooting :
      if (_driver.GetXButton() == true) {
        GetConfig().spinner.controller.Set(ControlMode::PercentOutput, 0.95);
      }
      SetIdle();
      break;
  }
}