# Compact WSL 2

``` PowerShell
wsl --shutdown
diskpart
# Open Microsoft DiskPart.
select vdisk file = "C:\Users\33160\AppData\Local\Packages\CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc\LocalState\ext4.vhdx"
attach vdisk readonly
compact vdisk
detach vdisk
exit
```
