import discord
from discord.ext import commands

class convo_cog(commands.Cog):
  def __init__(self, bot):
        self.bot = bot


  @commands.Cog.listener()
  async def on_message(self, message):
    if message.author.name != "Clint" and message.channel.name == "bar":
      await message.channel.send(getReply(message))

  @commands.command(name="laugh", help="This makes Clint laugh.")
  async def laugh(self,ctx):
    await ctx.send("hahahahaha!!!")


def getReply(statement):
    response = ""
    if statement.content == "hello":
      response = "Howdy! What can I get for you?"
    elif statement.content == "1 pineapple juice please":
      response = "Coming right up!"
    elif statement.content == "Knock Knock":
      response = "Who is there?"
    elif statement.content == "I am looking for a good spot in Galeswind!":
      response = "THE SIMMERING CAULDRON!!!"
    elif statement.content == "psst ever heard of the Crimson Children?":
      response = "GET OUT OF MY BAR!!!"
    else:
      response = "I didn't hear you"
    return response