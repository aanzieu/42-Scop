/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:56:54 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 15:25:18 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

t_bmp_header		*image_parse(t_bmp_header *bmp, FILE *file)
{
	bmp->datapos = *(int *)&(bmp->header[0x0A]);
	bmp->imagesize = *(int *)&(bmp->header[0x22]);
	bmp->width = *(int *)&(bmp->header[0x12]);
	bmp->height = *(int *)&(bmp->header[0x16]);
	if (bmp->imagesize == 0)
		bmp->imagesize = bmp->width * bmp->height * 3;
	if (bmp->datapos == 0)
		bmp->datapos = 54;
	if ((bmp->image_bmp =
				(unsigned char *)calloc(bmp->imagesize, sizeof(unsigned char))))
	{
		if ((!fread(bmp->image_bmp, 1, bmp->imagesize, file)))
		{
			fclose(file);
			return (NULL);
		}
	}
	fclose(file);
	return (bmp);
}

t_bmp_header		*error_file(char *str)
{
	dprintf(1, "%s", str);
	return (NULL);
}

t_bmp_header		*load_texture(t_glenv *master)
{
	t_bmp_header	*bmp;
	FILE			*file;

	if ((bmp = (t_bmp_header *)calloc(1, sizeof(t_bmp_header))))
	{
		file = fopen(master->file_bmp, "rb");
		if (!file)
			return (error_file("Image could not be opened\n"));
		if (fread(bmp->header, 1, 54, file) != 54)
		{
			free(bmp);
			fclose(file);
			return (error_file("Not a correct BMP file\n"));
		}
		if (bmp->header[0] != 'B' || bmp->header[1] != 'M')
		{
			free(bmp);
			fclose(file);
			return (error_file("Not a correct BMP file\n"));
		}
		return (image_parse(bmp, file));
	}
	return (NULL);
}
