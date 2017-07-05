import random, sys

###Gracze
class Player():
    def __init__(self,name):
        self.name = name
    def bet(self,betNum):
        self.number = betNum
    def isWin(self,numb):
        return self.number == numb
    def __str__(self):
        return self.name

###Silnik gry
class Game():
    def __init__(self,playersNumb,games):
        self.games = int(games)
        self.playersNumb = int(playersNumb)
        self.players = []
        self.winningNumbers=[]
        self.winners = {}
        for i in range(0,self.playersNumb):
            self.players.append(Player(raw_input("Imie gracza numer %d : "%i)))

    #glowna gra
    def startGame(self):
        for i in range(0,self.games):
            winner = random.randint(1,10)
            self.winningNumbers.append(winner)
            #print winner
            temp =[]
            for playe in self.players:
                playe.bet(raw_input("Zaklad %d gracza %s: "%(i+1,playe)))
                if playe.isWin(str(winner)):
                    temp.append(str(playe))
            self.winners[str(i+1)] = temp
            print "Zakaldy przyjete, let's play begin!"
    #statystyki gry
    def stats(self):
        print 
        print "---Statystyki---"
        print
        print "Wyniki Graczy:"
        for nams in self.players:
            print nams
        print
        print "Gry: %d"%self.games
        for i in range(0,self.games):
            print "Gra %d wynik: %d"%(i+1,self.winningNumbers[i])
            print "Zwyciezcy: %s"%(self.winners[str(i+1)])

gra = Game(sys.argv[1],sys.argv[2])
gra.startGame()
gra.stats()

exit()
