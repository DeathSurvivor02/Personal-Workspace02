import discord
from discord.ext import commands

from music import music_cog
from convo import convo_cog

client = commands.Bot(command_prefix="$", intents = discord.Intents.all())

client.add_cog(music_cog(client))
client.add_cog(convo_cog(client))

client.run("ODkwNTg1NjY5Njc4NzkyODM1.YUx8iQ.sqHUW7RG50wctXKS2d_-SABXh6o")