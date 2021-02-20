import base64
import requests
import datetime
from urllib.parse import urlencode
client_id = 'fa81ffad448145e7ba1148ad628764a7'
client_secret = '65970893646c4fbbb138d4a1fb2ce67f'
scope = "user-modify-playback-state user-read-playback-state"
scopec = urlencode({"scope":"user-modify-playback-state user-read-playback-state"})
redirect_uri = "http://localhost:8000/"
redirect_uric = urlencode({"redirect_uri":"http://localhost:8000/"})
token_url = 'https://accounts.spotify.com/authorize'


authPath = token_url + f'?client_id={client_id}&response_type=code&redirect_uri={redirect_uric}&scope={scopec}'
r = requests.get(authPath)
print(r.status_code)
#https://spotipy.readthedocs.io/en/2.16.1/
