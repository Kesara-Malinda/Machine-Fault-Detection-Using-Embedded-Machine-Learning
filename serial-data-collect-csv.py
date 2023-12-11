

import os
import uuid

# Third-party libraries
import serial

# Settings
DEFAULT_BAUD = 9600  # Default baud rate is now 9600
DEFAULT_PORT = "COM15"  # Default serial port is now COM15
DEFAULT_LABEL = "_unknown"  # Label prepended to all CSV files

# Create a file with unique filename and write CSV data to it
def write_csv(data, dir, label):

    # Keep trying if the file exists
    exists = True
    while exists:

        # Generate unique ID for file (last 12 characters from uuid4 method)
        uid = str(uuid.uuid4())[-12:]
        filename = label + "." + uid + ".csv"
        
        # Create and write to file if it does not exist
        out_path = os.path.join(dir, filename)
        if not os.path.exists(out_path):
            exists = False
            try:
                with open(out_path, 'w') as file:
                    file.write(data)
                print("Data written to:", out_path)
            except IOError as e:
                print("ERROR", e)
                return
    

# Configure serial port
ser = serial.Serial()
ser.port = DEFAULT_PORT
ser.baudrate = DEFAULT_BAUD

# Attempt to connect to the serial port
try:
    ser.open()
except Exception as e:
    print("ERROR:", e)
    exit()
print()
print("Connected to {} at a baud rate of {}".format(DEFAULT_PORT, DEFAULT_BAUD))
print("Press 'ctrl+c' to exit")

# Serial receive buffer
rx_buf = b''

# Make output directory
try:
    os.makedirs(".")
except FileExistsError:
    pass

# Loop forever (unless ctrl+c is captured)
try:
    while True:
        
        # Read bytes from serial port
        if ser.in_waiting > 0:
            while(ser.in_waiting):
                
                # Read bytes
                rx_buf += ser.read()
                
                # Look for an empty line
                if rx_buf[-4:] == b'\r\n\r\n':

                    # Strip extra newlines (convert \r\n to \n)
                    buf_str = rx_buf.decode('utf-8').strip()
                    buf_str = buf_str.replace('\r', '')

                    # Write contents to file
                    write_csv(buf_str, ".", DEFAULT_LABEL)
                    rx_buf = b''

# Look for keyboard interrupt (ctrl+c)
except KeyboardInterrupt:
    pass

# Close serial port
print("Closing serial port")
ser.close()
