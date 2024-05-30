import random
from typing import Tuple, Callable

# Define track segments
track_segments = ["straight", "turn", "straight", "turn", "straight", "finish"]

# Functional approach to get player's speed choice
def get_player_speed() -> int:
    while True:
        try:
            speed = int(input("Choose your speed (1-3): "))
            if speed in [1, 2, 3]:
                return speed
            else:
                print("Invalid speed. Please choose a speed between 1 and 3.")
        except ValueError:
            print("Invalid speed. Please choose a speed between 1 and 3.")

# Functional approach to simulate car movement
def move_car(position: int, speed: int, segment: str) -> int:
    if segment == "turn" and (speed == 3 or speed == 2):
        print("You crashed on a turn!")
        return 0  # crash
    return position + speed

# Functional approach to simulate a single segment
def play_segment(position: int, segment: str) -> Tuple[int, bool]:
    print(f"Current segment: {segment}")
    speed = get_player_speed()
    new_position = move_car(position, speed, segment)
    if new_position == 0:
        return position, True  # crashed
    print(f"New position: {new_position}\n")
    return new_position, False  # not crashed

# Main function to play the game
def main() -> None:
    print("Welcome to the Formula 1 Racing Game!")
    position = 0
    crashed = False

    for segment in track_segments:
        position, crashed = play_segment(position, segment)
        if crashed:
            print("Game Over! You crashed.")
            break
        if segment == "finish":
            break
    if not crashed:
        if position < len(track_segments) * 2:
                print("Game Over! You did not reach the finish line in time.")
        else: 
                print("Congratulations! You reached the finish line.")

if __name__ == "__main__":
    main()
