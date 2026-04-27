from setuptools import find_packages
from setuptools import setup

setup(
    name='kleman_interface',
    version='0.0.0',
    packages=find_packages(
        include=('kleman_interface', 'kleman_interface.*')),
)
