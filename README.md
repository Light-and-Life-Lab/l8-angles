# l8_angles

This package implements a simple Python interface to the USGS Landsat 8 tool for computing
per-pixel solar and sensor azimuth and zenith angles, from Angle Coefficient Files
(https://www.usgs.gov/core-science-systems/nli/landsat/solar-illumination-and-sensor-viewing-angle-coefficient-files)

## Installation
### Linux and MacOS

Pre-built wheels for **Linux** and **macOS** are published on the [Releases page](https://github.com/Light-and-Life-Lab/l8-angles/releases) for each tagged version. 

#### 1. Find the right wheel

Each release lists several `.whl` files, one per combination of Python version and platform. Each wheel has the format {distribution}-{version}-{python tag}-{abi tag}-{platform tag}.whl. Identify the wheel that matches your machine, for example if you are running with Python 3.10 on MacOS 11, the wheel name will look like:

`l8angles-1.0.0-cp310-cp310-macosx_11_0_arm64.whl`

Similarly, Python 3.10 on Linux would look like:

`l8angles-1.0.0-cp310-cp310-manylinux2014_x86_64.manylinux_2_17_x86_64.manylinux_2_28_x86_64.whl`

If you are unsure of your Python version, run:

```bash
python3 --version

```

The `cp3XX` in the filename should match your major/minor version (e.g. Python 3.11 -> `cp311`).

#### 2. Install directly from the release URL

Right-click the appropriate file on the [Releases page](https://github.com/Light-and-Life-Lab/l8-angles/releases) to copy its link, then run the following from the terminal:

```bash
`python -m pip install <paste-the-wheel-url-here>`

```

For example:

```bash
`python -m pip install https://github.com/Light-and-Life-Lab/l8-angles/releases/download/v1.0.0/l8angles-1.0.0-cp310-cp310-manylinux2014_x86_64.manylinux_2_17_x86_64.manylinux_2_28_x86_64.whl`

```

```

## Windows
Native Windows wheels are not built or supported. Windows users should install and run this library from within **[WSL (Windows Subsystem for Linux)](https://learn.microsoft.com/en-us/windows/wsl/install)**, then follow the Linux installation instructions above from inside your WSL environment.

## Usage
The package exposes a single function `calculate_angles`, taking the following parameters:
- metadata_file: str  
    Path to the ANG file
- angle_type: str (default: 'BOTH')  
    What angles to compute, either 'BOTH', 'SOLAR' or 'SATELLITE'
- subsample: int (default: 1)  
    Subsample factor, i.e. a subsample of 2 will halve the resolution
- bands: list (default: [1..11])  
    What bands to compute angles for

The function returns a dictionary, mapping angle type (sun/sat_az/zn, where az and zn is azimuth and zenith)
to lists of numpy 2D arrays. Each array in a list correspond to a single band.
The lists are ordered with respect to the input bands.

## Example
```python
import l8angles

data = l8angles.calculate_angles('./test_ANG.txt', angle_type='SOLAR',
                                 subsample=2, bands=[3,6,7])
```

