import requests

def getfact(num):
    url = f"http://numbersapi.com/{num}"

    r = requests.get(url)
    if r.status_code == 200:
        print(r.text)
    else:
        print(f"Error: {r.status.code}\n")
