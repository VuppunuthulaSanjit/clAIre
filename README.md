<div align="center">

<img src="https://img.shields.io/badge/Samsung%20Solve%20for%20Tomorrow-2026%20Semi--Finalist-1428A0?style=for-the-badge&logo=samsung&logoColor=white" />
<img src="https://img.shields.io/badge/Status-In%20Development-00C896?style=for-the-badge" />
<img src="https://img.shields.io/badge/Platform-Raspberry%20Pi%20%2B%20ESP32-C51A4A?style=for-the-badge&logo=raspberrypi&logoColor=white" />

# 🤖 clAIre
### *Autonomous AI Companion for Elderly & Disabled Individuals*

> **"Empowering independence through intelligent, compassionate technology."**

*A student-built assistive robot from Vernon Hills, IL — submitted to Samsung Solve for Tomorrow 2026*

</div>

---

## 🌟 What is clAIre?

In Lake County, thousands of seniors living alone face growing safety and health challenges. Falls, delayed emergency response, and isolation are among the most serious — and without support, everyday situations can quickly become emergencies.

**clAIre** (pronounced *Claire*) is an autonomous robotic companion designed to address exactly these challenges. Built by students at Vernon Hills High School, clAIre combines real-time obstacle detection, voice-activated emergency response, and autonomous following into one accessible, always-on assistant.

clAIre doesn't replace caregivers — it fills the gaps between them.

---

## ✨ Key Features

| Feature | Description |
|---|---|
| 🔊 **Verbal Obstacle Warnings** | Detects and announces obstacles in real time: *"Obstacle ahead — stairs on the left"* |
| 🚨 **Voice Emergency Calling** | Say *"Call for help"* and clAIre contacts emergency services immediately |
| 🧍 **Autonomous Following** | Tracks and follows the user at a safe distance (~1–2 meters), hands-free |
| 🎙️ **Natural Voice Commands** | Fully hands-free operation — no buttons, no screens required |
| 📱 **Companion App** | Interactive dashboard with alerts, reminders, health info, battery status & activity logs |
| 🔋 **All-Day Battery** | Dual 5,200 mAh lithium batteries — estimated **8–12 hours** of continuous operation |

---

## 🏗️ System Architecture

clAIre is built on **four integrated subsystems**:

```
┌─────────────────────────────────────────────────────────┐
│                      clAIre System                      │
├───────────────────┬────────────────────────────────────┤
│  Display &        │  Navigation &                      │
│  Interaction      │  Vision                            │
│  ─────────────    │  ─────────────                     │
│  Raspberry Pi     │  Camera (top-mounted)              │
│  Hamtysan Monitor │  Navigation ESP32                  │
│  Speakers (×2)    │  Obstacle detection &              │
│  Microphone       │  user tracking                     │
├───────────────────┼────────────────────────────────────┤
│  Motor Control    │  Power System                      │
│  ─────────────    │  ─────────────                     │
│  Main ESP32       │  2× 5200mAh Li-Ion batteries       │
│  PCB Motor Driver │  2× Crawler BDC80 ESCs             │
│  550 35T Motor    │  ~10,400 mAh total capacity        │
│  370 Planetary    │  Over-discharge protection         │
│  Motors (×2)      │                                    │
└───────────────────┴────────────────────────────────────┘
```

### Communication Flow

```
Camera → Navigation ESP32 → (ESP-NOW wireless) → Main ESP32
                                                       ↓
                                          PCB Motor Driver Board
                                          ↙               ↘
                                    Left ESC          Right ESC
                                    Left Motor        Right Motor

Microphone → Raspberry Pi → Voice Command Processing → Actions
                          ↘ Speaker Output (verbal feedback)
                          ↘ Companion App (via network)
```

---

## 🛠️ Hardware Components

| Component | Specification | Qty | Role |
|---|---|---|---|
| Main Computer | Raspberry Pi | 1 | System coordination, voice AI |
| Main Controller | ESP32 | 1 | Motor & behavioral control |
| Navigation Controller | ESP32 | 1 | Vision & obstacle processing |
| Camera | Pi Camera Module | 1 | Obstacle detection & user tracking |
| Display | Hamtysan Monitor | 1 | Visual interface |
| Primary Motor | 550 35T Brushed | 1 | Main propulsion |
| Secondary Motors | 370 Planetary | 2 | Drive support |
| Battery Controllers | Crawler BDC80 | 2 | Power/discharge management |
| Batteries | 5200mAh Lithium-Ion | 2 | Power source (×2 sides) |
| Speakers | Audio Output | 2 | Voice feedback |
| Microphone | Audio Input | 1 | Voice commands |
| Breadboard | Electronics Hub | 1 | Power distribution & connections |

---

## 🔄 Operational Modes

### 🚶 Normal Following Mode
1. Camera continuously tracks user's position
2. Navigation ESP32 calculates required movement
3. Robot maintains 1–2 meter safe following distance
4. Speed adjusts automatically to match user pace
5. Verbal confirmations keep user informed

### 🚧 Obstacle Detection Mode
1. Camera identifies obstacle in path
2. Navigation ESP32 classifies obstacle type and location
3. Motors receive immediate **STOP** command
4. clAIre announces: *"Obstacle ahead — [type] at [location]"*
5. Robot waits for clearance or user command

### 🆘 Emergency Response Mode
1. User speaks: *"Call for help"* or *"Emergency"*
2. Raspberry Pi processes the voice command
3. System confirms: *"Calling emergency services now"*
4. Emergency call initiated with location data if available
5. Audio connection maintained with services

### 🎙️ Voice Interaction Mode
- Always-on wake word detection
- Natural language command processing
- Verbal + visual confirmation for every action

---

## 📱 Companion App

The clAIre mobile app provides a real-time dashboard for users and caregivers:

- **Live Alerts** — Fall detection, obstacle events, emergency triggers
- **Medication Reminders** — Scheduled notifications with confirmation tracking
- **Activity Log** — Movement history and daily usage summaries
- **Battery Status** — Real-time power level monitoring
- **Health Data** — Secure storage for health info and care notes
- **Remote Monitoring** — Caregivers can check in from anywhere

---

## ⚡ Power Architecture

```
Battery 1 (5200mAh) → Crawler BDC80 #1 → Left Motor
                              ↓
                         Breadboard Hub
                              ↓
                    ┌─────────────────┐
                    │  Main ESP32     │
                    │  Nav ESP32      │
                    │  PCB Motor Driver│
                    │  Raspberry Pi   │
                    └─────────────────┘

Battery 2 (5200mAh) → Crawler BDC80 #2 → Right Motor
                              ↓
                         Breadboard Hub
```

- **Total capacity:** ~10,400 mAh
- **Estimated runtime:** 8–12 hours continuous
- **Protection:** Over-discharge protection via BDC80 controllers
- **Redundancy:** Independent left/right power channels

---

## ♿ Accessibility Impact

### For Users with Limited Vision
- Verbal obstacle warnings replace visual awareness
- Spoken environment descriptions
- Voice control — no need to see or read anything

### For Users with Limited Mobility
- Autonomous following — no carrying or pushing required
- Voice-activated emergency calling without a phone
- Hands-free operation throughout the day

### For Users with Cognitive Challenges
- Simple, natural voice commands
- Clear, unambiguous verbal responses
- Visual reinforcement on display
- Consistent, predictable behavior

### For Caregivers & Families
- Remote monitoring via companion app
- Emergency alerts delivered instantly
- Reduced physical and emotional caregiver burden
- Affordable, student-built solution

---

## 🗺️ Roadmap

- [x] Technical architecture & documentation
- [x] Hardware component selection
- [x] 3D printed chassis design (TinkerCad)
- [ ] Hardware assembly & wiring
- [ ] Navigation software development
- [ ] Voice AI integration
- [ ] Companion app completion
- [ ] Real-world testing & iteration
- [ ] Safety certification
- [ ] Community pilot program

---

## 👩‍💻 Team

Built by students at **Vernon Hills High School** — Lake County, IL.

*This project was developed as part of Samsung Solve for Tomorrow 2026, addressing real challenges faced by seniors in our local community.*

---

<div align="center">

**clAIre** — *Built with purpose, empathy, and impact.*

*Samsung Solve for Tomorrow 2026 | Vernon Hills High School*

</div>
