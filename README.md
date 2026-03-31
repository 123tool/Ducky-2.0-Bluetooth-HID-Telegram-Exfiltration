# 🐍 SPY-Ducky 2.0: Bluetooth HID & Telegram Exfiltration

![Payload](https://img.shields.io/badge/Payload-Telegram%20Integration-blue.svg)
![Hardware](https://img.shields.io/badge/Hardware-ESP32-red.svg)

**SPY-Ducky 2.0** bukan sekadar Rubber Ducky biasa. Tool ini menggunakan koneksi Bluetooth untuk menyuntikkan perintah (HID Attack) dan secara otomatis mengirimkan hasil data yang dicuri ke **Bot Telegram** Anda.

---

## 🚀 Fitur Unggulan
- **No Physical Trace**: Tidak perlu menancapkan USB ke target.
- **Telegram Exfiltration**: Hasil pencurian data (WiFi, Info System) langsung masuk ke HP Anda.
- **Cross-Platform**: Support Windows & Android (sebagai Bluetooth Keyboard).
- **Stealth**: Berjalan di background dan langsung menghapus jejak setelah eksekusi.

---

## 🛠️ Cara Install & Flash

### 1. Persiapan Arduino IDE
- Install Library `ESP32-BLE-Keyboard` di Arduino IDE.
- Pilih Board: `ESP32 Dev Module`.

### 2. Konfigurasi Bot Telegram
Buka file `spy_ducky.ino`, lalu sesuaikan bagian:
- `BOT_TOKEN`: Token dari BotFather.
- `CHAT_ID`: ID Telegram Anda.

### 3. Upload
Hubungkan ESP32 ke PC, klik **Upload**. Selesai!

---

## 📖 Panduan Penggunaan
1. Dekati target, nyalakan ESP32 (pakai baterai/powerbank).
2. Buka menu Bluetooth di laptop target, cari **"SPY-E Keyboard"**.
3. Klik **Connect/Pair**. 
4. ESP32 akan otomatis bekerja: Membuka terminal, mengambil data, mengirim ke Telegram, dan menutup terminal.

---
**Coded by SPY-E & 123Tool**
