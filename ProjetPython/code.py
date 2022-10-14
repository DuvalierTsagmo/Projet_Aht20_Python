"""
  Titre      : Code Python pour connecter Arduino à Python
  Auteur     : Duvalier Tsagmo
  Date       : 14/10/2022
  Description: ce programme stocke les donnees collecter aupres de notre AHT20
  Version    : 0.0.1
"""

# ici ce sont les librairie utiliser dans notre projet
import serial
import  time
import schedule

# ceci etre notre fonction qui vas nous permettre de stocker les donnees envoyer par notre uC sur lequel est brancher notre AHT20
def main_func():
    # ceci est le port Serial de communiaction avec notre Arduino
    arduino = serial.Serial('COM13', 9600)
    print('Established serial connection to Arduino')
    arduino_data = arduino.readline()

    decoded_values = str(arduino_data[0:len(arduino_data)].decode("utf-8"))
    list_values = decoded_values.split('x')

    for item in list_values:
        list_in_floats.append(float(item))

    print(f'Collected readings from Arduino: {list_in_floats}')

    arduino_data  =  0
    list_in_floats.clear()
    list_values.clear()
    arduino.close()
    print('Connection closed')
    print('<----------------------------->')


# ----------------------------------------Main Code------------------------------------
# Déclarer les variables à utiliser
list_values = []
list_in_floats = []

print('Program started')

# ceci concerne les Configurations de l'Arduino
schedule.every(5).seconds.do(main_func)

while True:
    schedule.run_pending()
    time.sleep(1)