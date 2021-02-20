import base64
import requests
import datetime
from urllib.parse import urlencode
client_id = 'fa81ffad448145e7ba1148ad628764a7'
client_secret = '65970893646c4fbbb138d4a1fb2ce67f'

class SpotifyAPI(object):
    access_token = None
    access_token_expires = datetime.datetime.now()
    access_token_did_expire = True
    client_id = None
    client_secret = None
    token_url = 'https://accounts.spotify.com/api/token'

    def __init__(self, client_id, client_secret, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.client_id = client_id
        self.client_secret = client_secret
    def get_client_credentials(self):
        client_id = self.client_id
        client_sec = self.client_secret
        if client_sec == None or client_id == None:
            raise Exception("You must set client_id and client_secret")
        client_creds = base64.b64encode(f"{client_id}:{client_sec}".encode())
        return client_creds.decode()

    def get_token_header(self):
        client_creds = self.get_client_credentials()
        return {
            "Authorization": f"Basic {client_creds}"
        }
    def get_token_data(self):
        return {
            "grant_type": "client_credentials"
        }
    def perform_auth(self):
        token_url = self.token_url
        token_data = self.get_token_data()
        token_headers = self.get_token_header()
        r = requests.post(token_url, data=token_data, headers=token_headers)
        if r.status_code not in range(200,299):
            return False
        now = datetime.datetime.now()
        data = r.json()
        access_token = data['access_token']
        expires_in = data['expires_in']
        expires = now + datetime.timedelta(seconds=expires_in)
        self.access_token = access_token
        self.access_token_expires = expires
        self.access_token_did_expire = expires < now
        return True
    def get_access_token(self):
        self.access_token_did_expire = datetime.datetime.now() > self.access_token_expires
        if(self.access_token == None or self.access_token_expires):
            self.perform_auth()
            return self.access_token
        return self.access_token
    def search(self, song):
        access_token = self.get_access_token()
        headers = {
            "Authorization": f"Bearer {access_token}"
        }
        endpoint = "https://api.spotify.com/v1/search"
        data = urlencode({"q": f"{song}", "type": "track"})

        lookup_url = f"{endpoint}?{data}"
        r = requests.get(lookup_url,headers=headers).json()
        tracks = r["tracks"]["items"]
        for item in tracks:
            print(f'{item["name"]} - by ', end="")
            for artist in item["artists"]:
                print(f'{artist["name"]} ', end="")
            print()
        return

client = SpotifyAPI(client_id, client_secret)
cont = 'y'
while(cont == 'y'):
    userIn = input("Search: ")
    client.search(str(userIn))
    print(5*"-")
    cont = input("Continue?: ")
    print("\n")
