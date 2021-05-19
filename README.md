# Unreal4_Escape-Room-Demo

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

A simple esacpe game demo based on Unreal4 Game Engine.

## Table of Contents

- [Background](#Background)
- [Exhibition](#Exhibition)
- [Install](#install)
- [Usage](#usage)
- [Structure](#Structure)
- [Maintainers](#Maintainers)
- [License](#license)

## Background

This is a very simple building escape game demo made by Unreal4 Game Engine.

In this demo, player needs to open two doors and escape the room. Player can use `wasd` or arrow keys to move and use mouse to change views. Additionally, player can use right mouse button to grab or release objects in the scene(button pressed to grab and button released to release).

## Exhibition

<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal4_Escape-Room-Demo/blob/main/Screenshots%20and%20GIFs/Exhibition.gif"/> </div>

<div align="center"> <img src="https://github.com/Yunxiang-Li/Unreal4_Escape-Room-Demo/blob/main/Screenshots%20and%20GIFs/Exhibition.jpg"/> </div>

## Install

I use Unreal4.25-4 and Visual Studio code for this project under Windows 10 environment.<br>
[Unreal download](https://www.unrealengine.com/en-US/download)<br>
[Visual Studio 2019 download](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=16)<br>
[Visual Code download](https://code.visualstudio.com/docs/?dv=win)

## Usage

1. Download this repo, open(or zip and open) the **Unreal4_Escape-Room-Demo** folder.

2. Double click the **BuildingEscape.uproject** file.

3. Let the **Unreal Game Engine** rebuild the demo.

## Structure

The whole project in Unreal contains two main folders, **Content** folder and **C++ Classes** folder.

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

[MIT license](https://github.com/Yunxiang-Li/Unreal4_Escape-Room-Demo/blob/master/LICENSE)
