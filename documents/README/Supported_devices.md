# YamBMS - Supported devices

[![Badge License: GPLv3](https://img.shields.io/badge/License-GPLv3-brightgreen.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Badge Version](https://img.shields.io/github/v/release/Sleeper85/esphome-jk-bms-can?include_prereleases&color=yellow&logo=DocuSign&logoColor=white)](https://github.com/Sleeper85/esphome-jk-bms-can/releases/latest)
![GitHub stars](https://img.shields.io/github/stars/Sleeper85/esphome-jk-bms-can)
![GitHub forks](https://img.shields.io/github/forks/Sleeper85/esphome-jk-bms-can)
![GitHub watchers](https://img.shields.io/github/watchers/Sleeper85/esphome-jk-bms-can)

## Supported ESP32

* [M5Stack Atom S3](Supported_devices_M5Stack_Atom_S3.md)
* [PVbrain2 with ESP32-S3](https://github.com/SeByDocKy/pvbrain2)
* [Build your own PCB with ESP32 or ESP32-S3](Supported_devices_Build_your_own_PCB.md)

## Supported BMS

All JK-B* and JK-PB* models with software@ version `>=6.0` are using the implemented protocol and should be supported.

See the [@syssi](https://github.com/syssi) [esphome-jk-bms](https://github.com/syssi/esphome-jk-bms) repository for more information.

Note: Other BMS brands already integrated with ESPhome can be added easily.

## Supported CAN Transceiver

| TJA1050 | TJA1051 | SN65HVD230 |
| --- | --- | --- |
| <img src="../../images/CAN_Transceiver_TJA1050.png" width="300"> | <img src="../../images/CAN_Transceiver_TJA1051.jpg" width="300"> | <img src="../../images/CAN_Transceiver_SN65HVD230.jpg" width="300"> |

| Atomic CAN Base | MCP2515 |
| --- | --- |
| <img src="../../images/CAN_Transceiver_Atomic_CAN_Base.png" width="450"> | <img src="../../images/CAN_Transceiver_MCP2515.png" width="450"> |

## Supported inverter

Inverters supporting CAN PYLON/Goodwe/SMA/Victron Low Voltage protocol should work, check your inverter manual to confirm.

The following are confirmed and known to work:

| Brand | Model | Satus | Reported by | Inverter battery | BMS | BMS link | ESP32 board | CAN name | CAN protocol | CAN board | Multi-BMS | Remarks |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Deye | SUN-3.6K-SG03LP1-EU | Working | [@Der_Hannes](https://diysolarforum.com/members/der_hannes.16949/) | Lithium 00 | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON 1.2 | SN65HVD230 **3.3V** | no | --- |
| Deye | SUN-5K-SG03LP1-EU | Working | [@vdiex](https://github.com/vdiex) | Lithium 00 | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON 1.2 | --- | no | --- |
| Deye | SUN-5K-SG03LP1-EU | Working | [@arzaman](https://github.com/arzaman) | Lithium 00 | JK-B* | BLE | Atom S3 | PYLON | PYLON 1.2 | [Atomic CAN base (CA-IS3050G)](https://docs.m5stack.com/en/atom/Atomic%20CAN%20Base) | no | --- |
| Deye | SUN-5K-SG03LP1-EU (3) | Working | [@widget4145](https://diysolarforum.com/members/widget4145.110784/) | Lithium 00 | JK-PB* (7) | RS485 | Atom S3 Lite | PYLON | PYLON 1.2 | [Atomic CAN base (CA-IS3050G)](https://docs.m5stack.com/en/atom/Atomic%20CAN%20Base) | yes | --- |
| Deye | SUN-6K-SG03LP1-EU | Working | [@Sleeper85](https://github.com/Sleeper85) | Lithium 00 | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON 1.2 | TJA1051T | no | --- |
| Deye | SUN-12K-SG04LP3-EU | Working | [@lucize](https://github.com/lucize) | Lithium 00 | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON 1.2 | --- | no | --- |
| Deye | SUN-12K-SG04LP3-EU | Working | [@luckylinux](https://github.com/luckylinux) | Lithium 00 | JK-B* | BLE | Atom S3 Lite | PYLON | PYLON 1.2 | [CANBus Unit (CA-IS3050G)](https://docs.m5stack.com/en/unit/can) | no | --- |
| Goodwe | 3648-ES (GW5048-ES) | Working | [@jirdol](https://github.com/jirdol) | --- | JK-B* | UART | ESP32 DevKit V1 | GOODWE | PYLON + | --- | no | --- |
| Goodwe | GW5000S-BP | Working | [@Uksa007](https://github.com/Uksa007) | Goodwe LX U5.4-L | JK-B* | UART | ESP32 DevKit V1 | GOODWE | PYLON + | --- | no | --- |
| Goodwe | GW5000S-BP & GW3600S-BP | Working | [@OselDusan7](https://github.com/OselDusan7) | --- | JK-B* | UART | ESP32 DevKit V1 | GOODWE | PYLON + | --- | no | --- |
| Sofar | ME 3000-SP | Working | [@starman](https://diysolarforum.com/members/starman.65151/) | --- | JK-B* | UART | ESP32 DevKit V1 | --- | --- | --- | no | --- |
| Sofar | HYD 5000-ES | Working | [@Paulfrench35](https://diysolarforum.com/members/paulfrench35.78523/) | --- | JK-B* | UART | ESP32 DevKit V1 | --- | --- | --- | no | --- |
| Sofar | HYD 5000-EP | Working | [@tonystrullu](https://diysolarforum.com/members/tonystrullu.91283/) | --- | JK-B* | UART | ESP32 DevKit V1 | --- | --- | --- | no | --- |
| Sofar | HYD 3600-ES | Working | [@chaosnature](https://diysolarforum.com/members/chaosnature.64395/) | Automatic | JK-PB* (2) | BLE | Atom S3 (display) | PYLON | PYLON 1.2 | [Atomic CAN base (CA-IS3050G)](https://docs.m5stack.com/en/atom/Atomic%20CAN%20Base) | yes | DIY Li-ion Growatt GBLI5001 converted. A 120 Ohm resistor had to be added on the Sofar side. Prefared over original BMS Manufacture's Management System. |
| Growatt | SPF 5000ES | Working | [@Paulfrench35](https://diysolarforum.com/members/paulfrench35.78523/) | CAN L52 | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON 1.2 | --- | no | --- |
| Growatt | SPF 5000ES | Working | [@cjdell](https://github.com/cjdell) | CAN L52 | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON 1.2 | --- | no | --- |
| Growatt | SPF 5000ES | Working | [@cinusik](https://diysolarforum.com/members/cinusik.109738/) | CAN L52 | JK-PB* (2) | BLE | Atom S3 (display) | PYLON | PYLON 1.2 | [CANBus Unit (CA-IS3050G)](https://docs.m5stack.com/en/unit/can) | yes | Best solution for the incomplete/wrong protocols implementation on JK Inverter BMSes and some inverters. |
| Solis | RHI-3.6K-48ES-5G | Working | [@cjdell](https://github.com/cjdell) | Pylon LV | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON + | SN65HVD230 **3.3V** | no | --- |
| Solis | S5-EH1P4.6K-L | Working | [@Baker0052](https://github.com/Baker0052) | Pylon LV | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON + | SN65HVD230 **3.3V** | no | --- |
| Solis | S5-EH1P6K-L | Working | [@MrPabloUK](https://github.com/MrPabloUK) | AoBo | JK-B* | UART | ESP32 DevKit V1 | SMA | SMA | [Adafruit CAN Pal](https://learn.adafruit.com/adafruit-can-pal/overview) | no | --- |
| Solis | RHI-3.6K-48ES-5G | Working | [@MrPabloUK](https://github.com/MrPabloUK) | AoBo | JK-B* | UART | ESP32 DevKit V1 | SMA | SMA | [Adafruit CAN Pal](https://learn.adafruit.com/adafruit-can-pal/overview) | no | --- |
| Solis | RHI-3K-48ES | Working | [@chaosnature](https://diysolarforum.com/members/chaosnature.64395/) | AoBo | JK-B* (2) | BLE | Atom S3 Lite | SMA | SMA | [Atomic CAN base (CA-IS3050G)](https://docs.m5stack.com/en/atom/Atomic%20CAN%20Base) | yes | DIY Li-ion Growatt GBLI5001 converted. |
| LuxPower | LXP SNA 5K | Working | [@shvmm](https://github.com/shvmm) | Li 02 | JK-B* | UART | ESP32 DevKit V1 | PYLON | PYLON + | SN65HVD230 **3.3V** | no | --- |
| --- | Turbo Energy | Working | [@ibikku](https://github.com/ibikku) | --- | JK-B* | UART | ESP32 DevKit V1 | --- | --- | --- | no | --- |
| SMA | Sunny Island  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Victron | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
