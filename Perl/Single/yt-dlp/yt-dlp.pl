#!/usr/bin/env perl

my $url = "https://yewtu.be/watch?v=_ffH3LROFZY";
my $command = "yt-dlp $url";

system($command);
