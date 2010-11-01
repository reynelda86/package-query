/*
 *  aur.h
 *
 *  Copyright (c) 2010 Tuxce <tuxce.net@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _AUR_H
#define _AUR_H
#include <alpm_list.h>


/*
 * AUR package
 */
typedef struct _aurpkg_t
{
	unsigned int id;
	char *name;
	char *version;
	unsigned int category;
	char *desc;
	unsigned int location;
	char *url;
	char *urlpath;
	char *license;
	unsigned int votes;
	unsigned short outofdate;
} aurpkg_t;

#define AUR_ID_LEN 	20

/*
 * JSON parse packages
 */
typedef struct _package_json_t
{
	alpm_list_t *pkgs;
	aurpkg_t *pkg;
	char current_key[AUR_ID_LEN];
	int level;
} package_json_t;

aurpkg_t *aur_pkg_new ();
aurpkg_t *aur_pkg_free (aurpkg_t *pkg);
aurpkg_t *aur_pkg_dup (const aurpkg_t *pkg);
int aur_pkg_cmp (const aurpkg_t *pkg1, const aurpkg_t *pkg2);
int aur_pkg_votes_cmp (const aurpkg_t *pkg1, const aurpkg_t *pkg2);

unsigned int aur_pkg_get_id (const aurpkg_t * pkg);
const char * aur_pkg_get_name (const aurpkg_t * pkg);
const char * aur_pkg_get_version (const aurpkg_t * pkg);
const char * aur_pkg_get_desc (const aurpkg_t * pkg);
const char * aur_pkg_get_url (const aurpkg_t * pkg);
const char * aur_pkg_get_urlpath (const aurpkg_t * pkg);
const char * aur_pkg_get_license (const aurpkg_t * pkg);
unsigned int aur_pkg_get_votes (const aurpkg_t * pkg);
unsigned short aur_pkg_get_outofdate (const aurpkg_t * pkg);



/*
 * AUR search function
 * Returns number of packages found
 * This function call print_package()
 */
int aur_search (alpm_list_t *targets);
int aur_info (alpm_list_t *targets);
/* aur_info_none print infomation even if package is not found */
int aur_info_none (alpm_list_t *targets);

/*
 * aur_get_str() get info for package
 * str returned should not be passed to free
 */
const char *aur_get_str (void *p, unsigned char c);

void aur_cleanup ();
#endif

/* vim: set ts=4 sw=4 noet: */
