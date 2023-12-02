# ['Game', '1:', '3', 'blue,', '4', 'red;', '1', 'red,', '2', 'green,', '6', 'blue;', '2', 'green']
# 12 red cubes, 13 green cubes, and 14 blue cubes in the bag

ans = 0
sum_of_power = 0
while True:
    game = input()
    if game == "":
        break
    game_split = game.split()
    game_num = int(game_split[1][0:-1])
    red = 0
    green = 0
    blue = 0
    maxred = 0
    maxblue = 0
    maxgreen = 0
    for i in range(0, len(game_split)):
        if (game_split[i] == "red,"):
            maxred = max(maxred, int(game_split[i - 1]))
        if (game_split[i] == "blue,"):
            maxblue = max(maxblue, int(game_split[i - 1]))
        if (game_split[i] == "green,"):
            maxgreen = max(maxgreen, int(game_split[i - 1]))

        if (game_split[i] == "red;"):
            maxred = max(maxred, int(game_split[i - 1]))
            blue = 0
            red = 0
            green = 0
        if (game_split[i] == "green;"):
            maxgreen = max(maxgreen, int(game_split[i - 1]))
            blue = 0
            red = 0
            green = 0
        if (game_split[i] == "blue;"):
            maxblue = max(maxblue, int(game_split[i - 1]))
            blue = 0
            red = 0
            green = 0

        if (game_split[i] == "blue"):
            maxblue = max(maxblue, int(game_split[i - 1]))
            this_power = maxblue * maxgreen * maxred
            sum_of_power = sum_of_power + this_power
            print("this power --> ", this_power)
        if (game_split[i] == "red"):
            maxred = max(maxred, int(game_split[i - 1]))
            this_power = maxblue * maxgreen * maxred
            sum_of_power = sum_of_power + this_power
            print("this power --> ", this_power)
        if (game_split[i] == "green"):
            maxgreen = max(maxgreen, int(game_split[i - 1]))
            this_power = maxblue * maxgreen * maxred
            sum_of_power = sum_of_power + this_power
            print("this power --> ", this_power)

print("sume of power: ", sum_of_power)
