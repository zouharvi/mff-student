class Student:
    """A simple class describing a student"""
    __col_override = False 
    __col = 'undefined'

    def __init__(self, sex):
        self.__sex = sex.lower()

    def get_preffered_color(self):
        if self.__col_override:
            return self.__col
        else:
            if self.__sex == 'm':
                return 'green'
            elif self.__sex == 'f':
                return 'blue'
            else:
                return 'red'

    def set_preffered_color(self, col):
        if self.__col != col:
            self.__col_override = True
            self.__col = col

vilda = Student('m')
print(vilda.get_preffered_color() == 'green', end='\n\t')
vilda.set_preffered_color('beige')
print(vilda.get_preffered_color() == 'beige', end='')