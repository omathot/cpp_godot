extends Camera2D

@onready var Char = get_node("/root/Main/Character")
#@onready var	my_camera = get_node("/root/Main/Shakable");

# ! add a free_movement bool to allow free movement of camera for player !

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	self.pos.x = Char.pos.x
	self.pos.y = Char.pos.y
