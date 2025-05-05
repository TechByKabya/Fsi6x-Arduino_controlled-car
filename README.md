# RC Controlled Bot (Relay + BTS7960 Motor Driver + RC Receiver)
**By Kabya Ghosh**  
**Date:** 6.6.2022

This project is a relay-enhanced RC-controlled robot car using BTS7960 motor drivers, RC transmitter PWM decoding, light/camera control via relays, and a buzzer for alerts. It reads PWM signals from a transmitter's AUX and throttle channels and maps them to motor control, light control, camera relay, and a startup buzzer tune.

---

## Features
- **Full directional control** using two PWM channels
- **Relay 1**: Turns on/off a wireless camera transmitter
- **Relay 2**: Controls light or another output device
- **Switchable Buzzer**: Alerts or signals with a tone or music
- **Start-up Sound**: Plays Star Wars “Cantina Band” on boot
- **Failsafe Stop**: All motors disabled if no signal is received

---

## Hardware Used
- Arduino UNO  
- RC Receiver (FS-iA6 or similar)  
- BTS7960 Dual Motor Driver  
- 2 x 12V DC Motors  
- 2 x Relay Modules  
- Buzzer Module  
- AUX Channel Input Switches  
- 2 PWM input pins from RC (Throttle & Steering)

---

## Pin Configuration

| Component         | Arduino Pin |
|------------------|-------------|
| RC Input 1       | D2          |
| RC Input 2       | D4          |
| Relay (Camera)   | D9          |
| Relay (Light)    | A0          |
| Buzzer           | A1          |
| Motor A (Right)  | RPWMa = 12, LPWMa = 10, ENAa = 5 |
| Motor B (Left)   | RPWMb = 8, LPWMb = 7, ENAb = 11 |
| AUX Inputs       | D3, D6, D13, A2 |

---

## Transmitter Channel Mapping

| Channel         | Action                        |
|----------------|-------------------------------|
| Channel 1 & 2   | Movement (forward, back, turn)|
| Switch 1 (D3)   | Camera Relay (on/off)         |
| Switch 2 (D6)   | Movement Enable/Disable       |
| Switch 3 (D13)  | Light Relay (on/off)          |
| Switch 4 (A2)   | Buzzer (on/off)               |

---

## Music Startup
On boot, the bot plays the **Star Wars Cantina Band** tune using the buzzer.  
*Melody taken from public domain and controlled with custom timing.*

---

## How It Works

1. RC PWM signals are read using `pulseIn()`.
2. Inputs are mapped to motor speed and direction using `analogWrite()`.
3. Based on switch channels, relays and buzzer are triggered.
4. A soft speed divider (`speed_slow`) smooths movement transitions.
5. Safety check disables motors if transmitter is not connected.

---

## How to Upload

1. Open Arduino IDE
2. Select Board: Arduino UNO
3. Copy `rc_controlled_bot.ino` into the editor
4. Upload via USB
5. Connect hardware as per pin config
6. Power your robot & transmitter — you're good to go!

---

## Author

**Kabya Ghosh**  
*Robotics & Embedded Systems Enthusiast*  
GitHub: [https://github.com/yourusername](https://github.com/TechByKabya)

---

## License

This project is open-source and free to use under the [MIT License](https://opensource.org/licenses/MIT)
