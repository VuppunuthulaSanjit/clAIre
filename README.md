<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title>clAIre — Autonomous AI Companion</title>
<link rel="preconnect" href="https://fonts.googleapis.com" />
<link href="https://fonts.googleapis.com/css2?family=Syne:wght@400;600;700;800&family=DM+Sans:ital,wght@0,300;0,400;0,500;1,300&display=swap" rel="stylesheet" />
<style>
  *, *::before, *::after { box-sizing: border-box; margin: 0; padding: 0; }

  :root {
    --blue: #1428A0;
    --blue-mid: #2563EB;
    --blue-light: #DBEAFE;
    --teal: #00C896;
    --teal-light: #DCFCE7;
    --ink: #0F172A;
    --ink-mid: #334155;
    --ink-muted: #64748B;
    --surface: #F8FAFC;
    --surface-alt: #F1F5F9;
    --border: #E2E8F0;
    --white: #ffffff;
    --radius: 12px;
    --radius-lg: 20px;
  }

  body {
    font-family: 'DM Sans', sans-serif;
    background: var(--surface);
    color: var(--ink);
    line-height: 1.7;
    font-size: 16px;
  }

  /* ── HERO ── */
  .hero {
    background: linear-gradient(135deg, #060C2E 0%, #0E1A5E 50%, #1428A0 100%);
    color: white;
    padding: 80px 40px 100px;
    position: relative;
    overflow: hidden;
    text-align: center;
  }
  .hero::before {
    content: '';
    position: absolute;
    inset: 0;
    background: radial-gradient(ellipse 70% 60% at 50% 80%, rgba(0,200,150,0.15), transparent);
  }
  .hero-grid {
    position: absolute;
    inset: 0;
    background-image:
      linear-gradient(rgba(255,255,255,0.03) 1px, transparent 1px),
      linear-gradient(90deg, rgba(255,255,255,0.03) 1px, transparent 1px);
    background-size: 40px 40px;
  }
  .hero-content { position: relative; z-index: 2; max-width: 760px; margin: 0 auto; }

  .badge-row {
    display: flex; flex-wrap: wrap; gap: 10px; justify-content: center;
    margin-bottom: 36px;
  }
  .badge {
    display: inline-flex; align-items: center; gap: 6px;
    padding: 6px 14px; border-radius: 100px;
    font-size: 12px; font-weight: 500; letter-spacing: 0.02em;
    border: 1px solid rgba(255,255,255,0.2);
    backdrop-filter: blur(8px);
  }
  .badge-samsung { background: rgba(20,40,160,0.6); color: #93C5FD; }
  .badge-status  { background: rgba(0,200,150,0.2);  color: #6EE7B7; }
  .badge-platform { background: rgba(255,255,255,0.1); color: #CBD5E1; }
  .badge-dot { width: 6px; height: 6px; border-radius: 50%; background: var(--teal); display: inline-block; }

  .hero h1 {
    font-family: 'Syne', sans-serif;
    font-size: clamp(64px, 10vw, 96px);
    font-weight: 800;
    letter-spacing: -0.04em;
    line-height: 1;
    margin-bottom: 8px;
  }
  .hero h1 span { color: var(--teal); }
  .hero-tagline {
    font-size: 18px; font-weight: 300; color: rgba(255,255,255,0.7);
    letter-spacing: 0.05em; text-transform: uppercase; margin-bottom: 24px;
  }
  .hero-quote {
    font-size: 17px; font-style: italic; color: rgba(255,255,255,0.6);
    max-width: 500px; margin: 0 auto; line-height: 1.6;
  }
  .hero-school {
    margin-top: 32px; font-size: 13px; color: rgba(255,255,255,0.4);
    letter-spacing: 0.1em; text-transform: uppercase;
  }

  /* ── LAYOUT ── */
  .page { max-width: 1000px; margin: 0 auto; padding: 60px 24px; }
  .section { margin-bottom: 72px; }

  .section-label {
    font-size: 11px; font-weight: 600; letter-spacing: 0.15em;
    text-transform: uppercase; color: var(--blue);
    margin-bottom: 12px; display: flex; align-items: center; gap: 10px;
  }
  .section-label::after {
    content: ''; flex: 1; max-width: 40px;
    height: 1px; background: var(--blue-mid);
  }

  h2 {
    font-family: 'Syne', sans-serif;
    font-size: clamp(26px, 4vw, 36px); font-weight: 700;
    letter-spacing: -0.02em; margin-bottom: 24px; color: var(--ink);
  }
  h3 { font-family: 'Syne', sans-serif; font-size: 18px; font-weight: 600; margin-bottom: 12px; color: var(--ink); }
  p { color: var(--ink-mid); margin-bottom: 16px; }

  /* ── WHAT IS IT ── */
  .intro-grid {
    display: grid; grid-template-columns: 1fr 1fr; gap: 24px;
  }
  @media (max-width: 640px) { .intro-grid { grid-template-columns: 1fr; } }

  .intro-card {
    background: var(--white); border-radius: var(--radius-lg);
    border: 1px solid var(--border); padding: 28px;
  }
  .intro-card.accent {
    background: linear-gradient(135deg, #060C2E, #1428A0);
    border-color: transparent; color: white;
  }
  .intro-card.accent p { color: rgba(255,255,255,0.75); }
  .intro-card.accent h3 { color: white; }

  /* ── FEATURES ── */
  .feature-grid {
    display: grid; grid-template-columns: repeat(auto-fit, minmax(280px, 1fr)); gap: 16px;
  }
  .feature-card {
    background: var(--white); border: 1px solid var(--border);
    border-radius: var(--radius); padding: 24px;
    transition: border-color 0.2s, transform 0.2s;
  }
  .feature-card:hover { border-color: var(--blue-mid); transform: translateY(-2px); }
  .feature-icon {
    width: 44px; height: 44px; border-radius: 10px;
    background: var(--blue-light); color: var(--blue);
    display: flex; align-items: center; justify-content: center;
    font-size: 20px; margin-bottom: 16px;
  }
  .feature-icon.teal { background: var(--teal-light); color: #059669; }
  .feature-title { font-weight: 600; font-size: 15px; margin-bottom: 6px; color: var(--ink); }
  .feature-desc { font-size: 14px; color: var(--ink-muted); line-height: 1.6; margin: 0; }

  /* ── ARCHITECTURE ── */
  .arch-grid {
    display: grid; grid-template-columns: 1fr 1fr; gap: 3px;
    border-radius: var(--radius-lg); overflow: hidden;
    border: 1px solid var(--border);
  }
  @media (max-width: 640px) { .arch-grid { grid-template-columns: 1fr; } }
  .arch-cell {
    background: var(--white); padding: 28px;
  }
  .arch-cell:nth-child(odd) { background: var(--surface-alt); }
  .arch-cell-title {
    font-family: 'Syne', sans-serif; font-size: 13px; font-weight: 700;
    letter-spacing: 0.08em; text-transform: uppercase; color: var(--blue);
    margin-bottom: 16px; padding-bottom: 12px; border-bottom: 1px solid var(--border);
  }
  .arch-item {
    display: flex; align-items: flex-start; gap: 10px;
    margin-bottom: 10px; font-size: 14px; color: var(--ink-mid);
  }
  .arch-dot {
    width: 6px; height: 6px; border-radius: 50%; background: var(--teal);
    margin-top: 8px; flex-shrink: 0;
  }

  /* ── MODES ── */
  .mode-grid {
    display: grid; grid-template-columns: repeat(auto-fit, minmax(220px, 1fr)); gap: 16px;
  }
  .mode-card {
    border-radius: var(--radius); padding: 24px;
    border: 1px solid var(--border);
  }
  .mode-card.blue  { background: #EFF6FF; border-color: #BFDBFE; }
  .mode-card.teal  { background: #F0FDF4; border-color: #BBF7D0; }
  .mode-card.red   { background: #FFF1F2; border-color: #FECDD3; }
  .mode-card.purple { background: #FAF5FF; border-color: #E9D5FF; }
  .mode-title { font-weight: 700; font-size: 14px; margin-bottom: 12px; }
  .mode-title.blue { color: #1E40AF; }
  .mode-title.teal { color: #065F46; }
  .mode-title.red  { color: #9F1239; }
  .mode-title.purple { color: #6B21A8; }
  .mode-steps { padding-left: 18px; }
  .mode-steps li { font-size: 13px; color: var(--ink-muted); margin-bottom: 6px; line-height: 1.5; }

  /* ── HARDWARE TABLE ── */
  .hw-table { width: 100%; border-collapse: collapse; border-radius: var(--radius); overflow: hidden; }
  .hw-table thead th {
    background: var(--ink); color: white;
    padding: 12px 16px; text-align: left; font-size: 12px;
    font-weight: 600; letter-spacing: 0.05em; text-transform: uppercase;
  }
  .hw-table tbody tr { border-bottom: 1px solid var(--border); }
  .hw-table tbody tr:last-child { border: none; }
  .hw-table tbody tr:nth-child(even) td { background: var(--surface-alt); }
  .hw-table td { padding: 12px 16px; font-size: 14px; color: var(--ink-mid); }
  .hw-table td:first-child { font-weight: 500; color: var(--ink); }
  .hw-badge {
    display: inline-block; padding: 2px 8px; border-radius: 4px;
    font-size: 11px; font-weight: 600;
    background: var(--blue-light); color: var(--blue);
  }

  /* ── VIDEO SECTION ── */
  .video-container {
    background: var(--ink);
    border-radius: var(--radius-lg);
    overflow: hidden;
    border: 1px solid #1E293B;
  }
  .video-header {
    padding: 20px 24px;
    border-bottom: 1px solid #1E293B;
    display: flex; align-items: center; gap: 12px;
  }
  .video-dot { width: 10px; height: 10px; border-radius: 50%; }
  .video-title-text {
    font-size: 13px; font-weight: 500; color: #94A3B8;
    margin-left: auto;
  }
  .video-embed-area {
    aspect-ratio: 16/9;
    position: relative;
    display: flex; align-items: center; justify-content: center;
    background: #0F172A;
  }
  .video-placeholder {
    text-align: center; padding: 40px;
  }
  .video-placeholder p {
    color: #475569; font-size: 14px; margin-top: 12px;
  }
  .play-btn {
    width: 72px; height: 72px; border-radius: 50%;
    background: rgba(20,40,160,0.5);
    border: 2px solid rgba(20,40,160,0.8);
    display: flex; align-items: center; justify-content: center;
    margin: 0 auto; cursor: pointer;
    transition: background 0.2s;
  }
  .play-btn:hover { background: var(--blue); }
  .play-btn svg { width: 28px; height: 28px; fill: white; margin-left: 4px; }

  .video-instructions {
    padding: 20px 24px; border-top: 1px solid #1E293B;
    font-size: 13px; color: #64748B; line-height: 1.6;
  }
  .video-instructions code {
    background: #1E293B; color: #7DD3FC;
    padding: 2px 8px; border-radius: 4px; font-size: 12px;
    font-family: 'Courier New', monospace;
  }
  .video-url-input-row {
    display: flex; gap: 10px; margin-top: 12px;
  }
  .video-url-input {
    flex: 1; padding: 8px 14px; border-radius: 8px;
    border: 1px solid #334155; background: #1E293B;
    color: #E2E8F0; font-size: 13px; font-family: inherit;
    outline: none;
  }
  .video-url-input:focus { border-color: var(--blue-mid); }
  .video-url-input::placeholder { color: #475569; }
  .video-embed-btn {
    padding: 8px 16px; border-radius: 8px;
    background: var(--blue); color: white;
    border: none; font-size: 13px; font-weight: 500;
    cursor: pointer; font-family: inherit;
    transition: background 0.2s;
  }
  .video-embed-btn:hover { background: #1E40AF; }

  /* ── TEAM ── */
  .team-grid {
    display: grid; grid-template-columns: repeat(auto-fit, minmax(160px, 1fr)); gap: 16px;
  }
  .team-card {
    background: var(--white); border: 1px solid var(--border);
    border-radius: var(--radius); padding: 22px 18px; text-align: center;
    transition: border-color 0.2s, transform 0.2s;
  }
  .team-card:hover { border-color: var(--blue-mid); transform: translateY(-2px); }
  .avatar {
    width: 52px; height: 52px; border-radius: 50%;
    display: flex; align-items: center; justify-content: center;
    font-family: 'Syne', sans-serif; font-size: 16px; font-weight: 700;
    margin: 0 auto 12px; letter-spacing: -0.02em;
  }
  .av-blue   { background: #DBEAFE; color: #1E40AF; }
  .av-teal   { background: #DCFCE7; color: #065F46; }
  .av-purple { background: #FAF5FF; color: #6B21A8; }
  .av-amber  { background: #FFFBEB; color: #92400E; }
  .av-pink   { background: #FDF2F8; color: #9D174D; }
  .team-name { font-weight: 600; font-size: 14px; color: var(--ink); margin-bottom: 4px; }
  .team-role {
    font-size: 11px; font-weight: 500; letter-spacing: 0.06em;
    text-transform: uppercase; color: var(--ink-muted);
  }

  /* ── ROADMAP ── */
  .roadmap-list { list-style: none; }
  .roadmap-item {
    display: flex; align-items: flex-start; gap: 16px;
    padding: 16px 0; border-bottom: 1px solid var(--border);
  }
  .roadmap-item:last-child { border: none; }
  .roadmap-check {
    width: 22px; height: 22px; border-radius: 50%;
    display: flex; align-items: center; justify-content: center;
    flex-shrink: 0; margin-top: 2px;
  }
  .check-done   { background: #DCFCE7; color: #059669; }
  .check-todo   { background: var(--border); color: var(--ink-muted); border: 1.5px solid var(--border); }
  .roadmap-item span { font-size: 15px; color: var(--ink-mid); }
  .roadmap-item.done span { color: var(--ink); }

  /* ── IMPACT ── */
  .impact-grid {
    display: grid; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); gap: 16px;
  }
  .impact-card {
    border-radius: var(--radius); padding: 24px;
    border-left: 3px solid;
  }
  .impact-card.vis  { background: #EFF6FF; border-color: var(--blue); }
  .impact-card.mob  { background: #F0FDF4; border-color: var(--teal); }
  .impact-card.cog  { background: #FAF5FF; border-color: #8B5CF6; }
  .impact-card.care { background: #FFF7ED; border-color: #F59E0B; }
  .impact-head { font-weight: 700; font-size: 13px; margin-bottom: 10px; text-transform: uppercase; letter-spacing: 0.06em; }
  .impact-head.vis  { color: var(--blue); }
  .impact-head.mob  { color: #065F46; }
  .impact-head.cog  { color: #6B21A8; }
  .impact-head.care { color: #92400E; }
  .impact-card ul { padding-left: 18px; }
  .impact-card li { font-size: 13px; color: var(--ink-muted); margin-bottom: 5px; line-height: 1.5; }

  /* ── FOOTER ── */
  .footer {
    background: var(--ink); color: rgba(255,255,255,0.5);
    text-align: center; padding: 40px 24px;
    font-size: 13px; letter-spacing: 0.03em;
  }
  .footer strong { color: rgba(255,255,255,0.8); font-weight: 600; }

  /* ── DIVIDER ── */
  .divider { height: 1px; background: var(--border); margin: 0 0 72px; }
</style>
</head>
<body>

<!-- ── HERO ─────────────────────────────────────────────── -->
<div class="hero">
  <div class="hero-grid"></div>
  <div class="hero-content">
    <div class="badge-row">
      <span class="badge badge-samsung">⊕ Samsung Solve for Tomorrow 2026 &mdash; Semi-Finalist</span>
      <span class="badge badge-status"><span class="badge-dot"></span> In Development</span>
      <span class="badge badge-platform">Raspberry Pi + ESP32</span>
    </div>
    <h1>cl<span>AI</span>re</h1>
    <p class="hero-tagline">Autonomous AI Companion for Elderly &amp; Disabled Individuals</p>
    <p class="hero-quote">"Empowering independence through intelligent, compassionate technology."</p>
    <p class="hero-school">Vernon Hills High School &nbsp;·&nbsp; Lake County, IL &nbsp;·&nbsp; 2026</p>
  </div>
</div>

<div class="page">

  <!-- ── WHAT IS CLAIRE ── -->
  <section class="section">
    <p class="section-label">Overview</p>
    <h2>What is clAIre?</h2>
    <div class="intro-grid">
      <div class="intro-card accent">
        <h3>The Problem</h3>
        <p>In Lake County, thousands of seniors living alone face growing safety and health challenges. Falls, delayed emergency response, and isolation are among the most serious — and without support, everyday situations can quickly become emergencies.</p>
      </div>
      <div class="intro-card">
        <h3>Our Solution</h3>
        <p><strong>clAIre</strong> (pronounced <em>Claire</em>) is an autonomous robotic companion that combines real-time obstacle detection, voice-activated emergency response, and autonomous following into one accessible, always-on assistant.</p>
        <p style="margin:0; font-size:14px; color: var(--blue); font-weight:500;">clAIre doesn't replace caregivers — it fills the gaps between them.</p>
      </div>
    </div>
  </section>

  <div class="divider"></div>

  <!-- ── KEY FEATURES ── -->
  <section class="section">
    <p class="section-label">Capabilities</p>
    <h2>Key Features</h2>
    <div class="feature-grid">
      <div class="feature-card">
        <div class="feature-icon">🔊</div>
        <div class="feature-title">Verbal Obstacle Warnings</div>
        <p class="feature-desc">Detects and announces obstacles in real time: <em>"Obstacle ahead — stairs on the left."</em></p>
      </div>
      <div class="feature-card">
        <div class="feature-icon teal">🚨</div>
        <div class="feature-title">Voice Emergency Calling</div>
        <p class="feature-desc">Say <em>"Call for help"</em> and clAIre contacts emergency services immediately with location data.</p>
      </div>
      <div class="feature-card">
        <div class="feature-icon">🧍</div>
        <div class="feature-title">Autonomous Following</div>
        <p class="feature-desc">Tracks and follows the user at a safe distance (~1–2 meters), completely hands-free.</p>
      </div>
      <div class="feature-card">
        <div class="feature-icon teal">🎙️</div>
        <div class="feature-title">Natural Voice Commands</div>
        <p class="feature-desc">Fully hands-free operation — no buttons, no screens required. Always-on wake word detection.</p>
      </div>
      <div class="feature-card">
        <div class="feature-icon">📱</div>
        <div class="feature-title">Companion App</div>
        <p class="feature-desc">Dashboard with live alerts, reminders, health info, battery status, and activity logs for caregivers.</p>
      </div>
      <div class="feature-card">
        <div class="feature-icon teal">🔋</div>
        <div class="feature-title">All-Day Battery</div>
        <p class="feature-desc">Dual 5,200 mAh lithium batteries — estimated <strong>8–12 hours</strong> of continuous operation.</p>
      </div>
    </div>
  </section>

  <div class="divider"></div>

  <!-- ── SYSTEM ARCHITECTURE ── -->
  <section class="section">
    <p class="section-label">Technical</p>
    <h2>System Architecture</h2>
    <div class="arch-grid">
      <div class="arch-cell">
        <div class="arch-cell-title">Display &amp; Interaction</div>
        <div class="arch-item"><div class="arch-dot"></div><div>Raspberry Pi — system coordination &amp; voice AI</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>Hamtysan Monitor — visual interface</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>Dual speakers — audio output / verbal feedback</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>Microphone — voice command input</div></div>
      </div>
      <div class="arch-cell">
        <div class="arch-cell-title">Navigation &amp; Vision</div>
        <div class="arch-item"><div class="arch-dot"></div><div>Pi Camera Module — top-mounted, obstacle detection &amp; user tracking</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>Navigation ESP32 — vision &amp; obstacle processing</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>ESP-NOW wireless — low-latency inter-ESP communication</div></div>
      </div>
      <div class="arch-cell">
        <div class="arch-cell-title">Motor Control</div>
        <div class="arch-item"><div class="arch-dot"></div><div>Main ESP32 — behavioral &amp; motor control</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>PCB Motor Driver — drive logic</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>550 35T Brushed motor — main propulsion</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>370 Planetary motors (×2) — drive support</div></div>
      </div>
      <div class="arch-cell">
        <div class="arch-cell-title">Power System</div>
        <div class="arch-item"><div class="arch-dot"></div><div>2× 5,200 mAh Li-Ion batteries (~10,400 mAh total)</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>2× Crawler BDC80 ESCs — power/discharge management</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>Over-discharge protection — independent L/R channels</div></div>
        <div class="arch-item"><div class="arch-dot"></div><div>Estimated runtime: 8–12 hours continuous</div></div>
      </div>
    </div>
  </section>

  <div class="divider"></div>

  <!-- ── OPERATIONAL MODES ── -->
  <section class="section">
    <p class="section-label">Behavior</p>
    <h2>Operational Modes</h2>
    <div class="mode-grid">
      <div class="mode-card blue">
        <div class="mode-title blue">🚶 Normal Following</div>
        <ol class="mode-steps">
          <li>Camera continuously tracks user</li>
          <li>Nav ESP32 calculates movement</li>
          <li>Maintains 1–2 m safe distance</li>
          <li>Speed auto-matches user pace</li>
          <li>Verbal confirmations keep user informed</li>
        </ol>
      </div>
      <div class="mode-card teal">
        <div class="mode-title teal">🚧 Obstacle Detection</div>
        <ol class="mode-steps">
          <li>Camera identifies obstacle</li>
          <li>Classifies type and location</li>
          <li>Immediate STOP command to motors</li>
          <li>Announces: <em>"Obstacle ahead — [type] at [location]"</em></li>
          <li>Waits for clearance or command</li>
        </ol>
      </div>
      <div class="mode-card red">
        <div class="mode-title red">🆘 Emergency Response</div>
        <ol class="mode-steps">
          <li>User says "Call for help"</li>
          <li>Raspberry Pi processes command</li>
          <li>Confirms: "Calling emergency services now"</li>
          <li>Emergency call initiated with location</li>
          <li>Audio connection maintained</li>
        </ol>
      </div>
      <div class="mode-card purple">
        <div class="mode-title purple">🎙️ Voice Interaction</div>
        <ol class="mode-steps">
          <li>Always-on wake word detection</li>
          <li>Natural language processing</li>
          <li>Verbal + visual confirmation</li>
          <li>No buttons or screens required</li>
        </ol>
      </div>
    </div>
  </section>

  <div class="divider"></div>

  <!-- ── HARDWARE ── -->
  <section class="section">
    <p class="section-label">Components</p>
    <h2>Hardware Components</h2>
    <table class="hw-table">
      <thead>
        <tr>
          <th>Component</th>
          <th>Specification</th>
          <th>Qty</th>
          <th>Role</th>
        </tr>
      </thead>
      <tbody>
        <tr><td>Main Computer</td><td>Raspberry Pi</td><td><span class="hw-badge">×1</span></td><td>System coordination, voice AI</td></tr>
        <tr><td>Main Controller</td><td>ESP32</td><td><span class="hw-badge">×1</span></td><td>Motor &amp; behavioral control</td></tr>
        <tr><td>Navigation Controller</td><td>ESP32</td><td><span class="hw-badge">×1</span></td><td>Vision &amp; obstacle processing</td></tr>
        <tr><td>Camera</td><td>Pi Camera Module</td><td><span class="hw-badge">×1</span></td><td>Obstacle detection &amp; user tracking</td></tr>
        <tr><td>Display</td><td>Hamtysan Monitor</td><td><span class="hw-badge">×1</span></td><td>Visual interface</td></tr>
        <tr><td>Primary Motor</td><td>550 35T Brushed</td><td><span class="hw-badge">×1</span></td><td>Main propulsion</td></tr>
        <tr><td>Secondary Motors</td><td>370 Planetary</td><td><span class="hw-badge">×2</span></td><td>Drive support</td></tr>
        <tr><td>Battery Controllers</td><td>Crawler BDC80 ESC</td><td><span class="hw-badge">×2</span></td><td>Power/discharge management</td></tr>
        <tr><td>Batteries</td><td>5,200 mAh Lithium-Ion</td><td><span class="hw-badge">×2</span></td><td>~10,400 mAh total capacity</td></tr>
        <tr><td>Speakers</td><td>Audio Output</td><td><span class="hw-badge">×2</span></td><td>Voice feedback</td></tr>
        <tr><td>Microphone</td><td>Audio Input</td><td><span class="hw-badge">×1</span></td><td>Voice commands</td></tr>
      </tbody>
    </table>
  </section>

  <div class="divider"></div>

  <!-- ── VIDEO DEMO ── -->
  <section class="section">
    <p class="section-label">Demo</p>
    <h2>Video Demonstration</h2>
    <div class="video-container">
      <div class="video-header">
        <div class="video-dot" style="background:#FF5F57;"></div>
        <div class="video-dot" style="background:#FEBC2E;"></div>
        <div class="video-dot" style="background:#28C840;"></div>
        <span class="video-title-text">clAIre — Live Demo</span>
      </div>
      <div class="video-embed-area" id="videoArea">
        <div class="video-placeholder">
          <div class="play-btn">
            <svg viewBox="0 0 24 24"><path d="M8 5v14l11-7z"/></svg>
          </div>
          <p>Video demonstration coming soon.<br/>Paste a YouTube or video URL below to embed.</p>
        </div>
      </div>
      <div class="video-instructions">
        <strong style="color:#94A3B8;">Add your demo video:</strong> Paste a YouTube link or direct video URL to embed the demonstration here.
        <div class="video-url-input-row">
          <input class="video-url-input" id="videoUrl" type="text" placeholder="https://youtube.com/watch?v=... or https://..." />
          <button class="video-embed-btn" onclick="embedVideo()">Embed ↗</button>
        </div>
      </div>
    </div>
  </section>

  <div class="divider"></div>

  <!-- ── ACCESSIBILITY IMPACT ── -->
  <section class="section">
    <p class="section-label">Impact</p>
    <h2>Accessibility Impact</h2>
    <div class="impact-grid">
      <div class="impact-card vis">
        <div class="impact-head vis">Limited Vision</div>
        <ul>
          <li>Verbal obstacle warnings replace visual awareness</li>
          <li>Spoken environment descriptions</li>
          <li>Voice control — no need to see or read</li>
        </ul>
      </div>
      <div class="impact-card mob">
        <div class="impact-head mob">Limited Mobility</div>
        <ul>
          <li>Autonomous following — no carrying or pushing</li>
          <li>Voice-activated emergency calling without a phone</li>
          <li>Hands-free operation throughout the day</li>
        </ul>
      </div>
      <div class="impact-card cog">
        <div class="impact-head cog">Cognitive Challenges</div>
        <ul>
          <li>Simple, natural voice commands</li>
          <li>Clear, unambiguous verbal responses</li>
          <li>Visual reinforcement on display</li>
          <li>Consistent, predictable behavior</li>
        </ul>
      </div>
      <div class="impact-card care">
        <div class="impact-head care">Caregivers &amp; Families</div>
        <ul>
          <li>Remote monitoring via companion app</li>
          <li>Emergency alerts delivered instantly</li>
          <li>Reduced caregiver burden</li>
          <li>Affordable, student-built solution</li>
        </ul>
      </div>
    </div>
  </section>

  <div class="divider"></div>

  <!-- ── ROADMAP ── -->
  <section class="section">
    <p class="section-label">Progress</p>
    <h2>Roadmap</h2>
    <ul class="roadmap-list">
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Technical architecture &amp; documentation</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Hardware component selection</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>3D printed chassis design (TinkerCad)</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Hardware assembly &amp; wiring</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Navigation software development</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Voice AI integration</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Companion app completion</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Real-world testing &amp; iteration</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Safety certification</span>
      </li>
      <li class="roadmap-item done">
        <div class="roadmap-check check-done">✓</div>
        <span>Community pilot program</span>
      </li>
    </ul>
  </section>

  <div class="divider"></div>

  <!-- ── TEAM ── -->
  <section class="section">
    <p class="section-label">The Team</p>
    <h2>Meet the Builders</h2>
    <div class="team-grid">
      <div class="team-card">
        <div class="avatar av-blue">JA</div>
        <div class="team-name">Jairus</div>
        <div class="team-role">Engineer</div>
      </div>
      <div class="team-card">
        <div class="avatar av-teal">AD</div>
        <div class="team-name">Adin</div>
        <div class="team-role">Engineer</div>
      </div>
      <div class="team-card">
        <div class="avatar av-purple">SH</div>
        <div class="team-name">Shashank</div>
        <div class="team-role">UI / UX</div>
      </div>
      <div class="team-card">
        <div class="avatar av-amber">CA</div>
        <div class="team-name">Caleb</div>
        <div class="team-role">UI / UX</div>
      </div>
      <div class="team-card">
        <div class="avatar av-pink">RI</div>
        <div class="team-name">Ritika</div>
        <div class="team-role">Outreach</div>
      </div>
    </div>
    <p style="margin-top:24px; font-size:14px; color:var(--ink-muted);">
      Built by students at <strong style="color:var(--ink);">Vernon Hills High School</strong> — Lake County, IL.
      Developed for Samsung Solve for Tomorrow 2026, addressing real challenges faced by seniors in our local community.
    </p>
  </section>

</div>

<!-- ── FOOTER ── -->
<footer class="footer">
  <p><strong>clAIre</strong> — Built with purpose, empathy, and impact.</p>
  <p style="margin-top:8px;">Samsung Solve for Tomorrow 2026 &nbsp;·&nbsp; Vernon Hills High School</p>
</footer>

<script>
function embedVideo() {
  const url = document.getElementById('videoUrl').value.trim();
  if (!url) return;
  const area = document.getElementById('videoArea');

  let embedUrl = url;
  const yt = url.match(/(?:youtube\.com\/watch\?v=|youtu\.be\/)([A-Za-z0-9_-]+)/);
  if (yt) embedUrl = 'https://www.youtube.com/embed/' + yt[1];

  const isVideo = url.match(/\.(mp4|webm|ogg)$/i);

  area.innerHTML = '';
  if (isVideo) {
    const v = document.createElement('video');
    v.src = url; v.controls = true;
    v.style.cssText = 'width:100%;height:100%;display:block;';
    area.appendChild(v);
  } else {
    const f = document.createElement('iframe');
    f.src = embedUrl; f.allowFullscreen = true;
    f.allow = 'accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture';
    f.style.cssText = 'width:100%;height:100%;border:none;display:block;';
    area.appendChild(f);
  }
}
</script>
</body>
</html>
