import firebase_admin
from firebase_admin import credentials, db
import json

class Logger():
    def init_database(self):
        print("_________________________________")
        print("Carregando dados da Base de dados...")
        print("_________________________________")
    
    def data_send(self):
        print("Dados enviados para o Json")
        print("_________________________________")
    
    def data_complete(self,data):
        print("Dados inseridos:")
        print(data)
        print("_________________________________")

class Parser():
    queue = []
    lock = 0
    logger = Logger()
    
    def __init__(self):
        cred = credentials.Certificate("credentials.json")
        firebase_admin.initialize_app(cred, {
            'databaseURL': 'https://teste-1-d91e7-default-rtdb.firebaseio.com/'
        })

        self.reference = db.reference('/Lancamentos')

    def listen_database(self,func):
        self.reference.listen(func)

    def generate_json_file(self):
        result_list = [{
        "AceleracaoInicial": entry["AceleracaoInicial"],
        "Distancia": entry["Distancia"],
        "Pressao(PSI)": entry["Pressao(PSI)"],
        "Velocidade": entry["Velocidade"]}      
        for entry in self.queue]

        with open("output.json", "w") as json_file:
            json.dump(result_list, json_file, indent=2)

        self.logger.data_send()

    def get_last_launch(self,event):
        if self.lock:
            self.data = self.reference.get()
            key_last_launch = list(self.data.keys())[-1]
            if(self.data[key_last_launch].__len__() == 4):
                del self.queue[0]
                self.queue.append(self.data[key_last_launch])
                self.generate_json_file()
                self.logger.data_complete(self.data[key_last_launch])
        else:
            self.lock = 1

    def get_last_launches(self):
        self.logger.init_database()
        self.data = self.reference.get()
        for i in range(-3,0):
            key_last = list(self.data.keys())[i]
            self.queue.append(self.data[key_last])
        self.generate_json_file()
    
parser = Parser()
parser.get_last_launches()
parser.listen_database(parser.get_last_launch)