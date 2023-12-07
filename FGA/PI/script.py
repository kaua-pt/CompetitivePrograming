import firebase_admin
from firebase_admin import credentials, db
import json

class Parser():
    queue = []

    def __init__(self):
        cred = credentials.Certificate("credentials.json")
        firebase_admin.initialize_app(cred, {
            'databaseURL': 'https://teste-1-d91e7-default-rtdb.firebaseio.com/'
        })

        self.reference = db.reference('/Lancamentos')

    def listen_database(self,func):
        self.reference.listen(func)

    def get_last_launch(self):
        self.data = self.reference.get()
        key_last_launch = list(self.data.keys())[-1]

        if(self.data[key_last_launch].__len__() == 4):
            return self.data[key_last_launch]

    def get_last_three_launches(self,event):
        data = self.get_last_launch()
        if(data):
            self.queue.append(data)
            if(self.queue.__len__() > 3):
                del self.queue[0]
            return self.parse_info()
        
    def parse_info(self):
        new_dict = {}
        count = 1
        for elem in self.queue:
            new_dict[f'{count}'] = elem
            count += 1
        print(json.dumps(new_dict))
        return json.dumps(new_dict)
    
parser = Parser()
parser.listen_database(parser.get_last_three_launches)