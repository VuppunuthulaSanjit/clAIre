# clAIre: AI-Powered Assistive Mobility Companion
**Samsung Solve for Tomorrow 2026 | Project clAIre**

clAIre (Collaborative Life Assistant & Intelligent Robotic Entity) is an autonomous assistive robot designed to support elderly individuals in Lake County. It bridges the gap between technology and senior care through autonomous following, obstacle detection, and emergency voice response.

---

## 📺 Project Video
> **[Watch our Samsung Solve for Tomorrow Submission Here]**
> 
> [![Project clAIre Video](https://img.shields.io/badge/YouTube-Watch%20Video-red?style=for-the-badge&logo=youtube)](INSERT_YOUTUBE_LINK_HERE)

---

## 📸 Gallery
| **The Robot (clAIre)** | **TinkerCad Design** |
| :--- | :--- |
| ![clAIre Build](./images/claire_physical.jpg) | ![3D Design](./images/claire_cad.png) |
| *Final autonomous build.* | *Mechanical design for 3D printing.* |

| **Caregiver Dashboard** | **Community Impact** |
| :--- | :--- |
| ![App Screenshot](./images/app_dashboard.png) | ![Senior Testing](./images/senior_test.jpg) |
| *Mobile app for remote monitoring.* | *Field testing with local seniors.* |

---

## 👥 Our Team
| Member | Role | Key Contributions |
| :--- | :--- | :--- |
| **Ritika** | Project Lead | Problem identification & specialist interviews. |
| **Jairus** | Hardware Engineer | 3D design (TinkerCad) & hardware assembly. |
| **Shashank** | Software Developer | Mobile app UI/UX & backend dashboard. |
| **Caleb** | Robotics Specialist | Motor control logic & navigation testing. |
| **Nathan** | Media Lead | Video production & technical documentation. |
---

## 🛠 Technical Overview (f=cde)
* **Functions:** Autonomous user tracking, verbal obstacle warnings, and voice-activated emergency calling.
* **Components:** Dual ESP32 Microcontrollers, Raspberry Pi 4, PiCam, 5200mAh Li-Ion batteries.
* **Design/Engineering:** Modular 3D-printed chassis utilizing ESP-NOW for low-latency communication between vision and drive systems.

---

## 📂 File Structure
* `/src/navigation`: ESP32 code for motor control and following.
* `/src/interaction`: Raspberry Pi Python code for AI voice assistant.
* `/design`: TinkerCad STL files and circuit diagrams.
