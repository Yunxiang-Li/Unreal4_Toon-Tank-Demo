# Unreal4_Escape-Room-Demo

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

The whole project in Unreal contains *3* main folders,  **Assets** folder, **Content** folder and **C++ Classes** folder.

Under **Content** folder, there are altogether **5** subfolders:

1. **Blueprints folder**: contains a Blueprint Class which called **DefaultPawn_BP** indicates the modified default pawn class.

2. **Levels folder**: contains the demo's level.

3. **MedievalDungeon** folder: contains all **2** objects we need in this demo.

4. **Sound** folder: contains the door open/close sound file

5. **Models** folder: contains all models we need in this demo which has **4** subfolders:

      5.1. **Instances** folder: contains **5** material instances we need in this demo such as `MI_Door`, `MI_Wall` and so on.

      5.2. **Materials** folder: contains **5** materials we need in this demo such as `M_Brass`, `M_Cell` and so on.

      5.3. **StaticMeshes** folder: contains **2** static meshes we need in this demo. They are `SM_DoorFrame` and `SM_Door`.

      5.4. **Textures** folder: contains **4** textures we need in this demo such as `T_Cell_BC`, `T_Door_BC` and so on.

## Maintainers

[@Yunxiang-Li](https://github.com/Yunxiang-Li).

## License

[MIT license](https://github.com/Yunxiang-Li/Unreal4_Toon-Tank-Demo/blob/main/LICENSE)
