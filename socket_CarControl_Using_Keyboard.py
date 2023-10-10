import socket
import keyboard
# ESP32 IP address and port
esp32_ip = '192.168.43.75' # enter your own 
esp32_port = 3000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((esp32_ip, esp32_port))

def main():
    print("Press any key (Ctrl+C to exit):")
    flag =1 
    while True:
        try:
            event = keyboard.read_event()
            if event.event_type == keyboard.KEY_DOWN:
                if event.name == event.name and flag == 1:
                    client_socket.send(event.name.encode())
                    flag =0
            else:
                flag =1
                name = "stop"
                client_socket.send(name.encode())
        except KeyboardInterrupt:
            client_socket.close()
            break
main()








