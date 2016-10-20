# FolderCompare
A small utility that compares two similar folders to find unique files.

Built for a specific purpose during game development when a matched pair of texture atlases -one full colour, the other for alpha blending- out of folders of individual images. Most of the alpha blend images were auto-generated as simple masks using another in house utility, while some were unique. The alpha blend atlas has to match the full colour one exactly, so there can be no discrepancy on the file list going into each atlas - one less or more file and the generation time is wasted. This utility prevents that wasted time.
