import serial
import time

# Connect to the serial port (replace 'COM3' with your Arduino's port)
ser = serial.Serial('COM4', 9600, timeout=1)
time.sleep(2)  # Wait for the connection to establish

# Send a byte to the Arduino
ser.write(b'1')
send_time = time.time()  # Record the time immediately after sending

# Wait for a response and record the time when it's received
incoming = ser.readline().decode().strip()
receive_time = time.time()

# Calculate and print the delay
if incoming:
    arduino_time = int(incoming)
    delay = (receive_time - send_time) * 1000  # Convert to milliseconds
    print(f"Delay: {delay} ms")
else:
    print("No response from Arduino")

ser.close()  # Close the serial connection
