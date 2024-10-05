import arcade

CHARACTER_SCALING = 1
RIGHT_FACING = 0
LEFT_FACING = 1

class PlayerCharacter(arcade.Sprite):
    def __init__(self):
        super().__init__()
        self.filename = ':resources:images/animated_characters/robot/robot_idle.png'
        self.scale = CHARACTER_SCALING
        self.health = 1500
        self.center_x = 128
        self.center_y = 128

