from glob import glob

import numpy
from setuptools import Extension, setup

c_sources = sorted(glob("src/ias_lib/*.c")) + [
    "src/l8_angles.c",
]

setup(
    ext_modules=[
        Extension(
            name="l8angles",
            sources=["l8angles.pyx", *c_sources],
            include_dirs=["src", "src/ias_lib", numpy.get_include()],
            extra_compile_args=["-O2"],
            define_macros=[("NPY_NO_DEPRECATED_API", "NPY_1_7_API_VERSION")],
        ),
    ],
)
