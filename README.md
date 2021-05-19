# Unreal4_Toon-Tank-Demo

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

A simple 3d tank shooting game demo based on Unreal4 Game Engine.

## Table of Contents

- [Background](#Background)
- [Exhibition](#Exhibition)
- [Install](#install)
- [Usage](#usage)
- [Structure](#Structure)
- [Maintainers](#Maintainers)
- [License](#license)

## Background

This is a very simple 3d tank shooting game demo made by Unreal4 Game Engine(C++ codes and Blueprints).

In this demo, player can use `wasd` keys to control the toon tank(`w/s` keys to move forward or backward, `a/d` keys to rotate left or right) and left mouse key to shoot projectiles. In order to win the game, player needs to control the tank to destory all 4 turrets. If the player tank is destroyed by turrets' projectiles then the game is over and player loses.

## Exhibition

## Install

I use Unreal4.26.2 and Visual Studio code for this project under Windows 10 environment.<br>
[Unreal download](https://www.unrealengine.com/en-US/download)<br>
[Visual Studio 2019 download](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=16)<br>
[Visual Code download](https://code.visualstudio.com/docs/?dv=win)

## Usage

1. Download this repo, open(or zip and open) the **Unreal4_Toon-Tank-Demo** folder.

2. Double click the **ToonTanks.uproject** file.

3. Let the **Unreal Game Engine** rebuild the demo.

## Structure

The whole project in Unreal contains **2** main folders, **Content** folder and **C++ Classes** folder.

Under **Content** folder, there are altogether **3** subfolders:

1. **Assets** folder: contains **5** subfolders including all assets we need for this game demo.

      1.1. **Audio** folder: contains **2** sound wave audio files.

      1.2. **Effects** folder: contains **3** particle system effects.

      1.3. **Materials** folder: contains altogether **15** materials, material instances and material functions.

      1.4. **Meshes** folder: contains **6** static meshes.

      1.5. **Textures** folder: contains **3** textures.
      
2. **Blueprints** folder: contains **6** subfolders including all Blueprint classes and widget Blueprint we need for this game demo.

      2.1. **Actor** folder: contains **1** Blueprint class indicates the projectile.

      2.2. **Camera** folder: contains **2** Blueprint classes indicates camera shake effects when hit or explode.

      2.3. **GameModes** folder: contains **1** Blueprint class indicates our custom GameMode class.

      2.4. **Pawns** folder: contains **2** Blueprint classes indicates our tank and turret classes.

      2.5. **PlayerControllers** folder: contains **1** Blueprint class indicates our custom PlayerController class.
      
      2.6. **Widgets** folder: contains **2** widget Blueprint indicate `GameStart()` and `GameOver()` functions.

3. **Maps** folder: contains **1** level object indicates our main game map.

Under **C++ Classes** folder, there is **1** subfolder:

1. **ToonTanks** folder: contains **5** subfolders of C++ classes we need for this game demo.

      1.1. **Actor** folder: contains **1** `ProjectileBase` class indicates the projectile class.

      1.2. **Components** folder: contains **1** `HealthComponent` class indicates our custom health component for the tank and turrets.

      1.3. **GameModes** folder: contains **1** `TankGameModeBase` class indicates our custom GameModeBase class.

      1.4. **Pawns** folder: contains **3** classes, `PawnBase` class for all derived classes' parent class, `PawnTank` class for the tank and `PawnTurret` class for turrets.

      1.5. **PlayerControllers** folder: contains **1** `PlayerControllerBase` indicates our custom PlayerController class.
      
## Maintainers

[@Yunxiang-Li](https://github.com/Yunxiang-Li).

## License

[MIT license](https://github.com/Yunxiang-Li/Unreal4_Toon-Tank-Demo/blob/main/LICENSE)
