# clAIre: AI-Powered Assistive Mobility Companion
**Samsung Solve for Tomorrow 2026 | Project clAIre**

clAIre (Collaborative Life Assistant & Intelligent Robotic Entity) is an autonomous assistive robot designed to support elderly individuals and people with disabilities. By combining computer vision, voice recognition, and autonomous navigation, clAIre provides safety, independence, and peace of mind for seniors living alone.

## 🚀 Key Features
* **Autonomous Following:** Uses PiCam and ESP32 vision processing to track and accompany the user hands-free.
* **Intelligent Obstacle Detection:** Real-time identification of stairs, furniture, and hazards with verbal warnings.
* **Emergency Response:** Voice-activated emergency calling triggered by keywords like "Help" or "Emergency."
* **Health Dashboard:** Integrated app for caregivers to monitor battery life, activity logs, and medication reminders.

## 🛠 Technical System Architecture


The system operates on a multi-controller "Hub & Spoke" model:
1.  **Display & Interaction:** Raspberry Pi + Hamtysan Monitor (Voice & UI).
2.  **Vision & Navigation:** ESP32 + High-res Camera (Pathfinding & Obstacle detection).
3.  **Motor Control:** ESP32 + PCB Motor Driver Board (Propulsion & Steering).
4.  **Power System:** Dual 5200mAh Li-Ion batteries with Crawler BDC80 management.

## 💻 Technical Specifications
| Component | Specification |
| :--- | :--- |
| **Main Compute** | Raspberry Pi 4 / ESP32 |
| **Vision Processor** | ESP32-CAM |
| **Primary Motors** | 550 35T Brushed / 370 Planetary |
| **Power** | 10,400 mAh Total Capacity |
| **Communication** | ESP-NOW (Wireless Low-Latency) |

## 🌍 Community Impact
Developed for the Lake County community, clAIre addresses the critical "safety gap" for seniors. Our research shows that delayed emergency response is a primary fear for elderly residents; clAIre provides a 24/7 autonomous safety net that functions without the need for manual phone operation.

## 📂 Repository Structure
* `/src/vision`: ESP32-CAM obstacle detection scripts.
* `/src/navigation`: ESP-NOW communication and motor logic.
* `/src/app`: Dashboard code for caregiver monitoring.
* `/docs`: CAD (TinkerCad) files and circuit diagrams.
