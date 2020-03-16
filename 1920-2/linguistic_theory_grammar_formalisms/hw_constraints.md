# 1

- a: Vozidlo se dvěma koly. Konkrétní instance [bicycle, motorbike]
- b: Vozidlo nevyrobeno velorexem.
- c: Pokud je to výrobek cabrio, tak má convertible střechu.
- d: Je to výrobek cabrio právě když má convertible střechu.
- e: Pokud je to výrobek velorex, pak to není typ lorry ani bicycle, ovšem může být [motorbike, bus, cabrio, combi, saloon]

# 2

- a: Neunifikovatelné?
- b: Sporné.
- c: Sporné, neunifikovatelné.
- d: `lanovka` není definovaný typ.

# 3

- a: [combi] -> [BODY | BACK hatchback] 
- b: [MAKE rollsroyce] -> [car]
- c: [car; BODY | ROOF convertible] -> [COLOUR red]
- d: [WHEELS six] -> [lorry]

# 4

- a: Každé pohybující se vozidlo musí mít řidiče na palubě.

# 5

- a: Číslo větší než 1
- b: 2
- c: Nekonečno.

# 6

- a:
```
top
...
  vehicle
    make:make
    colour:colour
    owner:person
    wheels:number

  number
    zero
    nonzero
      previous:number
```
- b:
```
top
...
  vehicle
    make:make
    colour:colour
    owner:person
    wheels:number
    two_wheeled
      wheels:(previous:(previous:zero))
```

# 7

- a: [WHEELS | PREVIOUS | PREVIOUS | PREVIOUS nonzero] -> [lorry]
- b: [bicycle] -> [WHEELS zero]
- c: [cabrio] -> [MAKE velorex]
