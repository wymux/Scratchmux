import yt_dlp

yt_opts = {}

with yt_dlp.YoutubeDL(yt_opts) as ydl:
    ydl.download(["https://yewtu.be/watch?v=_ffH3LROFZY"])
