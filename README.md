# 🔐 RSA Encryption/Decryption on 8051 Microcontroller

## 📌 Overview
This project demonstrates the implementation of the **RSA Public Key Cryptosystem** on an **8051 microcontroller**.
It supports both **encryption** and **decryption** via a serial interface with a PC. The system is designed for educational purposes,
emphasizing secure key generation, Fermat primality testing, and ASCII-based communication.

## 🧠 Key Features

- RSA Key Pair Generation using 4-byte prime numbers `p` and `q`
- Fermat Primality Test (Security Level = 5)
- Public and Private Key calculation using Extended Euclidean Algorithm
- Text-based encryption and decryption via HyperTerminal or any serial terminal
- Communication over UART between PC and 8051 microcontroller
- ASCII-encoded plaintext and ciphertext data exchange

## 🔄 Workflow

1. User inputs 4-byte primes `p` and `q` via serial terminal.
2. 8051 checks primality using **Fermat Primality Test** (5 iterations).
3. Generates `n`, `e`, and computes `d` using Extended Euclidean Algorithm.
4. Receives plaintext from PC and encrypts it using public key.
5. Sends encrypted ciphertext to PC.
6. Optionally decrypts ciphertext to verify original message.

## 📡 Communication Protocol

- Baud Rate: `9600`
- Format: `8 data bits`, `no parity`, `1 stop bit` (8N1)
- Data format: ASCII characters

## 📋 Deliverables

- ✅ Complete C code for 8051 (Keil µVision)
- ✅ Working circuit with UART interface to PC
- ✅ PDF Report (modules, flow diagram, and testing)
- ✅ Proteus simulation (optional)

## 🧪 Testing

- Verified with example values:
  - p = 61, q = 53
  - Plaintext: `HELLO`
- Expected Ciphertext and correct decryption confirmed
- UART tested using TeraTerm and PuTTY


