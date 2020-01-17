 
import time
from random import randint
import logging
import os

def log(fonction_origine):
    def modif_fonction(*args, **kwargs):
        x = time.perf_counter() * 1000
        ret = fonction_origine(*args, **kwargs)
        logging.info("Running : " + fonction_origine.__name__ + "    [ exec-time = " + str(round(time.perf_counter() * 1000 - x, 3)) + " ms ]")
        return ret
    return modif_fonction


class CoffeeMachine():

    water_level = 100

    @log
    def start_machine(self):
        if self.water_level > 20:
            return True
        else:
            print("Please add water!")
            return False
            
    @log
    def boil_water(self):
        return "boiling..."

    @log
    def make_coffee(self):
        if self.start_machine():
            for _ in range(20):
                time.sleep(0.1)
                self.water_level -= 1
            print(self.boil_water())
            print("Coffee is ready!")

    @log
    def add_water(self, water_level):
        time.sleep(randint(1, 5))
        self.water_level += water_level
        print("Blub blub blub...")

if __name__ == "__main__":
    if os.path.exists('./machine.log'):
        os.remove('./machine.log')
    logging.basicConfig(filename='machine.log', level=logging.INFO)
    machine = CoffeeMachine()
    for i in range(0, 5):
        machine.make_coffee()
    machine.make_coffee()
    machine.add_water(70)