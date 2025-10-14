# ELCB
# 🔄 Automatic Bypass Protection & Trip Indication System

A microcontroller-based prototype that simulates **automatic bypass and trip logic** for a power protection system.  
Built using **Arduino**, **relays**, **rotary encoder**, and an **OLED/LCD display**, this system demonstrates how **normal**, **primary trip**, and **backup trip** operations can be managed in a smart protective relay environment.

---

## ⚙️ Features

- 🟢 **Normal Mode:** Load powered through Relay A (main path).  
- 🟡 **Primary Trip:** Load disconnected — trip indication via LED & Relay B.  
- 🔴 **Backup Trip & Bypass:** Temporary bypass path (Relay C) restores load after a short delay.  
- 🔁 **Rotary Encoder Control:** Rotate to simulate protection stages (Normal → Trip → Bypass).  
- 🧠 **Microcontroller Logic:** Handles state transitions and ensures safety interlocks.

---

## 🧩 Hardware Components

| Component | Description | Pin |
|------------|-------------|-----|
| Arduino Uno/Nano | Microcontroller | — |
| Rotary Encoder | Mode selection | CLK → D3, DT → D4 |
| LED (Green) | Normal Indicator | D6 |
| LED (Yellow) | Primary Trip | D7 |
| LED (Red) | Backup Trip | D5 |
| Relay A | Normal Operation | D8 |
| Relay B | Primary Trip | D9 |
| Relay C | Backup / Bypass | D10 |

---

## 🧠 Working Principle

1. **Normal Operation**
   - Green LED and Relay A **ON**
   - Load powered normally

2. **Primary Trip**
   - Yellow LED and Relay B **ON**
   - Load disconnected (Relay A OFF)
   - Trip condition displayed

3. **Backup Trip + Bypass**
   - Red LED and Relay C **ON** after short delay
   - Bypass path re-energizes the load temporarily
   - Trip indication maintained

---

## 🖼️ System Flow
Normal Mode → Primary Trip → Backup Trip (Bypass)


---

## 💻 Code Overview

### Main Functions:
- `shaft_moved()` → Detects rotary encoder rotation to change system state  
- `updateOutputs()` → Updates relays, LEDs, and OLED display  
- `loop()` → Monitors current state & prints debug info via Serial  

---

## 🧪 How to Use

1. Upload the Arduino code to your board.  
2. Connect all components as per the pin configuration.  
3. Rotate the encoder knob to switch between:
   - **0:** Normal  
   - **1:** Primary Trip  
   - **2:** Backup Trip (with Bypass)
4. Watch LED indicators, relay clicks, and OLED/LCD messages update in real time.

---

## 🧷 Safety Note

> ⚠️ This project is for **educational and low-voltage demonstration purposes only**.  
> Do **not** use this prototype with live AC mains or real power systems.

---

## 📸 Future Enhancements

- Add GSM alerts during trip events  
- Integrate IoT (NodeMCU/ESP8266) for remote monitoring  
- Automatic fault logging and trip time analysis  
- MATLAB-based simulation of protection logic

---

## 📚 License

This project is open-source under the **MIT License** — free to modify and use for learning or demonstrations.

---



