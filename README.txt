RPG Maker MZ Clean Launcher
===========================

This builds a small Windows launcher EXE online through GitHub Actions.
It launches:

  files\Game.exe

with the working directory set to:

  files

Final game folder should look like this:

  Your Game/
    Your Game.exe        <- launcher built by GitHub Actions
    files/
      Game.exe           <- RPG Maker MZ deployed executable
      package.json
      index.html
      data/
      img/
      audio/
      js/
      nw.dll
      nw.pak
      etc.

How to use:

1. Create a GitHub repo.
2. Upload Launcher.cpp.
3. Upload the .github folder exactly as included.
4. Open the repo on GitHub.
5. Go to Actions.
6. Select Build Launcher.
7. Click Run workflow.
8. When it finishes, download the launcher-exe artifact.
9. Put Your Game.exe beside your files folder.

To rename the final EXE:

Open .github/workflows/build.yml and change this part:

  /Fe:"Your Game.exe"

Example:

  /Fe:"Tales of Lewdia.exe"

Also change this part near the bottom:

  path: Your Game.exe

Example:

  path: Tales of Lewdia.exe

Do not use packers, BAT-to-EXE tools, AutoHotkey, Enigma, or UPX if you want lower antivirus false-positive risk.
